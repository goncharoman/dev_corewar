/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:40:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/30 01:20:40 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_bool	is_cmd(char *arg, const char *command)
{
	if (!arg || !command)
		return (false);
	return (!ft_strcmp(arg, command + 1));
}

void	write_int(t_program *program, uint32_t size, int32_t value)
{
	uint8_t	n;

	n = 0;
	while (size)
	{
		program->code[program->position++ + size - 1] = \
			(uint8_t)((value >> n) & 0xff);
		n += 8;
		size--;
	}
}
