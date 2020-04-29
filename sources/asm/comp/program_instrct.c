/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_instrct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:09:49 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/29 23:18:19 by ujyzene          ###   ########.fr       */
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
		if (label->init_position == -1)
			label->init_position = program->position;
	}
}

static uint8_t	proc_arg(t_op *op, t_token *token, t_program *program, int arg)
{
	const uint8_t	types[12] = {0,0,0,0,T_REG,T_DIR,T_DIR,T_IND,T_IND,0,0,0};

	if (!(op->args_types[arg] & types[token->type]))
		/* TODO: написать отдельный обработчик ошибок */
		exit(1);
	if (token->type == INDL || token->type == DIRL)
		write_call(op, token, program);
	else if (token->type == DIR || token->type == IND)
		write_dir(op, token, program);
	else
		write_reg(token, program);
	return (types[token->type]);

}

static void		proc_oper(t_op *op, t_list **head, t_program *program)
{
	t_token		*token;
	int			arg;
	uint8_t		typescode;
	int32_t		op_position;

	arg = 0;
	typescode = 0;
	op_position = op->args_typescode ? program->position++ : -1;
	while ((token = next_token(head)))
	{
		if (token->type >= REG && token->type <= INDL)
			typescode |= proc_arg(op, token, program, arg++);
		else
			exit(1);
		if ((token = next_token(head))->type == SEP && arg < op->args_n)
			continue;
		else if (token->type == ENDLN && arg == op->args_n)
			break;
		else
			exit(1);
	}
	if (op_position > -1 && typescode)
		program->code[op_position] = typescode;
}

static void 	proc_instruction(t_token *token, t_list **head,
					t_program *program)
{
	t_op		*op;

	if ((op = get_oper(token->value)))
	{
		program->code[program->position++] = op->code;
		proc_oper(op, head, program);
	}
	else
		exit(1);
}

void			get_program_code(t_list **head_lst, t_program *program)
{
	t_token		*token;

	while ((token = next_token(head_lst))->type != END)
	{
		if (program->position >= program->size)
			increase_code_size(program);
		if (token->type == LBL)
			proc_label(token, program);
		else if (token->type == OPR)
			proc_instruction(token, head_lst, program);
		else if (token->type == ENDLN)
			continue;
		else
			exit(1);
	}
}
