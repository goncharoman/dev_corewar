/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:01:17 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:14:36 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(int32_t id, int32_t addr, t_bool carry)
{
	ft_printf("P %4d | zjmp %d %s\n", id + 1, addr, carry ? "OK" : "FAILED");
}

uint32_t			handler_zjmp(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		addr;

	offset = 1 + (int)cursor->oper->args_typescode;
	addr = get_avalue(vm->arena, cursor, &offset, 0);
	if (cursor->carry)
	{
		cursor->pc = mem_addr(cursor->pc + (addr % IDX_MOD));
		offset = 0;
	}
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, addr, cursor->carry);
	return (offset);
}
