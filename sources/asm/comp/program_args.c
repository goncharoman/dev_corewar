/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 22:09:07 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/30 01:16:11 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

void	write_call(t_op *op, t_token *token, t_program *program)
{
	uint32_t	size;
	t_label		*label;

	size = token->type == DIRL ? op->tdir_size : IND_SIZE;
	if (!(label = find_label(&program->labels , token->value)))
		add_label(&program->labels, (label = create_label(token->value, -1)));
	add_call(&label->calls, create_call(token, program->position, size));
	program->position += size;
}

void	write_dir(t_op *op, t_token *token, t_program *program)
{
	uint8_t	size;

	size = (token->type == DIR) ? op->tdir_size : IND_SIZE;
	write_int(program, size,
		size == 2 ? (int16_t)ft_atoi32(token->value) : ft_atoi32(token->value));
}

void	write_reg(t_token *token, t_program *program)
{
	write_int(program, 1, (int8_t)ft_atoi32(&token->value[1]));
}
