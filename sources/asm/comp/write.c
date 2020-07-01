/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:43:26 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:43:27 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

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
