/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:05:36 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:55:38 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

inline static void	log_oper(uint32_t id, int32_t addr, int32_t r)
{
	ft_printf("P %4d | lld %d r%d\n", id + 1, addr, r);
}

uint32_t			handler_lld(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		value;
	int32_t		r;

	offset = 1 + cursor->oper->args_typescode;
	if (cursor->oper_args_types[0] == T_DIR)
	{
		value = get_value(vm->arena, cursor->pc + offset,
			cursor->oper->tdir_size);
		offset += cursor->oper->tdir_size;
	}
	else
	{
		value = get_value(vm->arena,
			cursor->pc + get_addr(vm->arena, cursor->pc + offset),
			DIR_SIZE);
		offset += IND_MEM_SIZE;
	}
	cursor->carry = !value;
	r = get_byte(vm->arena, cursor->pc + offset++);
	cursor->reg[r - 1] = value;
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, value, r);
	return (offset);
}
