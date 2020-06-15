/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:57:56 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:14:23 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(uint32_t id, int32_t value[2], int32_t r)
{
	ft_printf("P %4d | or %d %d r%d\n", id + 1, value[0], value[1], r);
}

uint32_t			handler_or(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		value[2];
	int32_t		r;
	int32_t		result;

	offset = 1 + cursor->oper->args_typescode;
	value[0] = get_avalue(vm->arena, cursor, &offset, 0);
	value[1] = get_avalue(vm->arena, cursor, &offset, 1);
	r = get_byte(vm->arena, cursor->pc + offset++);
	result = value[0] | value[1];
	cursor->reg[r - 1] = result;
	cursor->carry = !result;
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, value, r);
	return (offset);
}
