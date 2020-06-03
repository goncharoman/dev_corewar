/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:54:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/17 22:22:57 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_op.h>

inline static void	log_oper(uint32_t id, int32_t r[3])
{
	ft_printf("P %4d | sub r%d r%d r%d\n", id + 1, r[0], r[1], r[2]);
}

uint32_t	handler_sub(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		arg[3];
	int32_t		value;

	offset = 1 + cursor->oper->args_typescode;
	arg[0] = get_byte(vm->arena, cursor->pc + offset++);
	arg[1] = get_byte(vm->arena, cursor->pc + offset++);
	arg[2] = get_byte(vm->arena, cursor->pc + offset++);
	cursor->reg[arg[2] - 1] = \
		(value = cursor->reg[arg[0] - 1] - cursor->reg[arg[1] - 1]);
	cursor->jump = !value;
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, arg);
	return (offset);
}
