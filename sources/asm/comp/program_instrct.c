/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_instrct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:09:49 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 17:25:02 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

static void		proc_label(t_token *token, t_program *program)
{
	t_label	*label;

	if (!(label = find_label(&program->labels, token->value)))
		add_label(&program->labels,
			create_label(token->value, program->position));
	else
	{
		if (label->position == -1)
			label->position = program->position;
	}
}

static uint8_t	proc_arg(t_op *op, t_token *token, t_program *program,
				int32_t begin_instruct)
{
	if (token->type == DIR || token->type == IND)
		proc_numeric(op, token, program);
	else if (token->type == REG)
		proc_reg(token, program);
	else
		proc_call(op, token, program, begin_instruct);
	if (token->type == DIR || token->type == DIRL)
		return (DIR_CODE);
	else if (token->type == IND || token->type == INDL)
		return (IND_CODE);
	else
		return (REG_CODE);
}

static uint8_t	proc_args(t_op *op, t_list **head, t_program *program,
				int32_t begin_instruct)
{
	uint8_t	typescode;
	int		i;
	t_token	*token;

	i = 0;
	typescode = 0;
	while ((token = next_token(head)))
	{
		if (is_arg(token->type))
		{
			if (!(op->args_types[i] & ttype_to_targ(token->type)))
				invalid_arg(&program, token, op, i);
			typescode |=
				proc_arg(op, token, program, begin_instruct) << (2 * (3 - i++));
		}
		else
			token_error(&program, token);
		if ((token = next_token(head))->type == SEP && i < op->args_n)
			continue ;
		else if (token->type == ENDLN && i == op->args_n)
			break ;
		else
			token_error(&program, token);
	}
	return (typescode);
}

static void		proc_instruction(t_token *token, t_list **head,
					t_program *program)
{
	t_op	*op;
	int32_t	typcodes_addr;
	uint8_t	typescode;

	if ((op = get_oper(token->value)))
	{
		program->code[program->position++] = op->code;
		if (op->args_typescode)
			typcodes_addr = program->position++;
		typescode = proc_args(op, head, program,
				program->position - 1 - op->args_typescode);
		if (op->args_typescode)
			program->code[typcodes_addr] = typescode;
	}
	else
		token_error(&program, token);
}

void			get_program_code(t_list **head_lst, t_program *program)
{
	t_token		*token;
	t_bool		err;

	err = true;
	while ((token = next_token(head_lst))->type != END)
	{
		err = false;
		if (program->position >= program->size)
			increase_code_size(program);
		if (token->type == LBL)
			proc_label(token, program);
		else if (token->type == OPR)
			proc_instruction(token, head_lst, program);
		else if (token->type == ENDLN)
			continue;
		else
			token_error(&program, token);
	}
	if (err)
		token_error(&program, token);
}
