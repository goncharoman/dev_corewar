/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:02:01 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:12:09 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(t_cursor *cursor, int32_t addr[2], int32_t r)
{
	ft_printf("P %4d | ldi %d %d r%d\n", cursor->id + 1, addr[0], addr[1], r);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			addr[0], addr[1], addr[0] + addr[1],
			cursor->pc + (addr[0] + addr[1]) % IDX_MOD);
}

uint32_t			handler_ldi(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		addr[2];
	int32_t		r;

	offset = 1 + cursor->oper->args_typescode;
	addr[0] = get_avalue(vm->arena, cursor, &offset, 0);
	addr[1] = get_avalue(vm->arena, cursor, &offset, 1);
	r = get_byte(vm->arena, cursor->pc + offset++);
	cursor->reg[r - 1] = bcode_to_int(vm->arena,
			(cursor->pc + ((addr[0] + addr[1]) % IDX_MOD)),
			DIR_SIZE);
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor, addr, r);
	return (offset);
}
