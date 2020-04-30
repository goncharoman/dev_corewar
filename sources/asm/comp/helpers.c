/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:40:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 00:05:26 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_bool	is_cmd(char *arg, const char *command)
{
	if (!arg || !command)
		return (false);
	return (!ft_strcmp(arg, command + 1));
}

void	write_int(t_program *program, uint8_t size, int32_t value)
{
	uint8_t	i;

	i = 0;
	while (i < size)
		program->code[program->position++] = \
			(uint8_t)((value >> (8 * (size - ++i))) & 0xff);
}
