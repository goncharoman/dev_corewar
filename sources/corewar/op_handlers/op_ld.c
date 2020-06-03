/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:51:20 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/18 01:59:54 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(int32_t id, int32_t value, int32_t r_id)
{
	ft_printf("P %4d | ld %d r%d\n", id + 1, value, r_id);
}

uint32_t	handler_ld(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		value;
	int32_t		id;

	offset = 1 + cursor->oper->args_typescode;
	value = get_avalue(vm->arena, cursor, &offset, 0);
	id = get_byte(vm->arena, cursor->pc + offset++);
 	cursor->reg[id - 1] = value;
	cursor->jump = !value;
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, value, id);
	return (offset);
}
