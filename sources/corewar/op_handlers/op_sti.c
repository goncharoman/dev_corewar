/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:04:01 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:55:54 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

inline static void	log_oper(t_cursor *cursor, int32_t addr[2], int32_t r)
{
	ft_printf("P %4d | sti r%d %d %d\n", cursor->id + 1, r, addr[0], addr[1]);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			addr[0], addr[1], addr[0] + addr[1],
			cursor->pc + (addr[0] + addr[1]) % IDX_MOD);
}

uint32_t			handler_sti(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		r;
	int32_t		value;
	int32_t		addr[2];

	offset = 1 + cursor->oper->args_typescode;
	r = get_byte(vm->arena, cursor->pc + offset++);
	value = cursor->reg[r - 1];
	addr[0] = get_avalue(vm->arena, cursor, &offset, 1);
	addr[1] = get_avalue(vm->arena, cursor, &offset, 2);
	write_int(vm->arena, cursor->pc + ((addr[0] + addr[1]) % IDX_MOD),
		DIR_SIZE, value);
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor, addr, r);
	return (offset);
}
