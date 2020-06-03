/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:08:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 05:33:24 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | lfork %d (%d)\n", cursor->id + 1, addr,
		cursor->pc + addr);
}

uint32_t	handler_lfork(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		addr;

	offset = 1 + cursor->oper->args_typescode;
	addr = get_avalue(vm->arena, cursor, &offset, 0);
	add_cursor(&(vm->cursors), dup_cursor(cursor, addr));
	vm->cursors_count++;
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor, addr);
	return (offset);
}
