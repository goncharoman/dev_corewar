/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:52:28 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:55:51 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

inline static void	log_oper(int32_t id, int32_t r_id, int32_t addr)
{
	ft_printf("P %4d | st r%d %d\n", id + 1, r_id, addr);
}

uint32_t			handler_st(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		value;
	int32_t		arg[2];

	offset = 1 + (int)cursor->oper->args_typescode;
	arg[0] = get_byte(vm->arena, cursor->pc + offset++);
	value = cursor->reg[arg[0] - 1];
	if (cursor->oper_args_types[1] == T_IND)
	{
		arg[1] = get_addr(vm->arena, cursor->pc + offset);
		write_int(vm->arena, cursor->pc + (arg[1] % IDX_MOD), DIR_SIZE,
			value);
		offset += IND_MEM_SIZE;
	}
	else
	{
		arg[1] = get_byte(vm->arena, cursor->pc + offset);
		cursor->reg[arg[1] - 1] = value;
		offset += REG_MEM_SIZE;
	}
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, arg[0], arg[1]);
	return (offset);
}
