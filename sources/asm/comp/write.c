/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:32:43 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:32:55 by dschimme         ###   ########.fr       */
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
