/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:09:49 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/22 21:39:48 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	proc_label(t_token *token, t_program *program, unsigned *offset)
{
	return;
}

static void proc_instruction(t_token *token, t_program *program,
		unsigned *offset)
{
	t_oper	*oper;

	if ((oper = get_oper(token)))
	{

	}
	else
		exit(1);
}

void		get_program_code(t_list **head_lst, t_program *program)
{
	t_token		*token;
	unsigned	offset;

	offset = 0;
	while ((token = next_token(head_lst))->type != END)
	{
		if (offset >= program->code_size)
			increase_code_size(program);
		if (token->type == LBL)
			proc_label(token, program, &offset);
		else if (token->type == OPR)
			proc_instruction(token, program, &offset);
		else if (token->type == ENDLN)
			continue;
		else
			exit(1);
	}
}
