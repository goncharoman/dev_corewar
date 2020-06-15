/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 05:35:27 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:03:14 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int32_t	get_value(uint8_t *mem, uint32_t addr, uint8_t size)
{
	return (bcode_to_int(mem, addr, size));
}

int32_t	get_byte(uint8_t *mem, uint32_t addr)
{
	return (mem[mem_addr(addr)]);
}

int32_t	get_addr(uint8_t *mem, uint32_t addr)
{
	return (get_value(mem, addr, IND_SIZE));
}

int32_t	get_avalue(uint8_t *mem, t_cursor *cursor, uint32_t *offset,
			uint8_t index)
{
	int32_t	value;

	value = 0;
	if (cursor->oper_args_types[index] == REG_CODE)
		value = cursor->reg[get_byte(mem, cursor->pc + *offset) - 1];
	else if (cursor->oper_args_types[index] == DIR_CODE)
		value = get_value(mem, cursor->pc + *offset,
			cursor->oper->tdir_size);
	else if (cursor->oper_args_types[index] == IND_CODE)
		value = get_value(mem,
			cursor->pc + (get_addr(mem, cursor->pc + *offset) % IDX_MOD),
			DIR_SIZE);
	*offset += type_size(cursor->oper_args_types[index],
		cursor->oper->tdir_size);
	return (value);
}
