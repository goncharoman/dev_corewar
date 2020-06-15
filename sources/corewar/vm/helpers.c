/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:37:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:04:22 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

t_bool		is_int(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (false);
	return (true);
}

uint32_t	type_size(uint8_t type, uint8_t t_dir_size)
{
	if (type & T_REG)
		return (REG_MEM_SIZE);
	if (type & T_DIR)
		return (t_dir_size);
	if (type & T_IND)
		return (IND_MEM_SIZE);
	return (0);
}

int32_t		mem_addr(int32_t addr)
{
	return ((addr %= MEM_SIZE) < 0 ? addr + MEM_SIZE : addr);
}

int32_t		bcode_to_int(uint8_t *mem, int32_t addr, int32_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(mem[mem_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		result += (sign) ?
			(mem[mem_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8) :
			mem[mem_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	return (sign ? ~result : result);
}

void		write_int(uint8_t *mem, int32_t addr, uint32_t size, int32_t value)
{
	uint8_t	i;

	i = 0;
	while (i < size)
		mem[mem_addr(addr++)] = (uint8_t)((value >> (8 * (size - ++i))) & 0xFF);
}
