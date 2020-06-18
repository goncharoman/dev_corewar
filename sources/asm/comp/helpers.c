/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:40:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 22:30:21 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_bool		is_cmd(char *arg, const char *command)
{
	if (!arg || !command)
		return (false);
	return (!ft_strcmp(arg, command + 1));
}

uint32_t	write_int(uint8_t *code, uint32_t position, uint8_t size,
			int32_t value)
{
	uint8_t	i;

	i = 0;
	while (i < size)
		code[position++] = (uint8_t)((value >> (8 * (size - ++i)) & 0xFF));
	return ((uint32_t)size);
}

void		write_num(t_program *program, uint8_t size, int32_t value)
{
	program->position += \
		write_int(program->code, program->position, size, value);
}

t_bool		is_arg(t_type type)
{
	return ((t_bool)(type == REG || type == DIR || type == DIRL ||
				type == IND || type == INDL));
}

uint8_t		ttype_to_targ(t_type token_type)
{
	if (token_type == DIR || token_type == DIRL)
		return (T_DIR);
	if (token_type == IND || token_type == INDL)
		return (T_IND);
	if (token_type == REG)
		return (T_REG);
	return (0);
}
