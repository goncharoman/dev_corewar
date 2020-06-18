/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 22:09:07 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 22:18:52 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

void	proc_call(t_op *op, t_token *token, t_program *program,
			int32_t instrct_position)
{
	uint8_t		size;
	t_label		*label;

	size = token->type == DIRL ? op->tdir_size : IND_SIZE;
	if (!(label = find_label(&program->labels, token->value)))
		add_label(&program->labels, (label = create_label(token->value, -1)));
	add_call(&label->calls,
		create_call(token, program->position, instrct_position, size));
	program->position += size;
}

void	proc_numeric(t_op *op, t_token *token, t_program *program)
{
	uint8_t	size;

	size = (token->type == DIR) ? op->tdir_size : IND_SIZE;
	write_num(program, size,
		size == 2 ? (int16_t)ft_atoi32(token->value) : ft_atoi32(token->value));
}

void	proc_reg(t_token *token, t_program *program)
{
	write_num(program, 1, (int8_t)ft_atoi32(&token->value[1]));
}
