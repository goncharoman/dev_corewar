/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:40:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 18:42:01 by ujyzene          ###   ########.fr       */
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
