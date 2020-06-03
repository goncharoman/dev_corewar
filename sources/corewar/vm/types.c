/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 05:27:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 05:51:03 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static uint8_t	get_type( uint8_t index)
{
	return (index < 1 && index > 3 ? 0 : index);
}

void			get_types(t_vm *vm, t_cursor *cursor)
{
	uint8_t			typescode;
	const uint8_t	types[4] = {0, T_REG, T_DIR, T_IND};

	if (cursor->oper->args_typescode)
	{
		typescode = vm->arena[mem_addr(cursor->pc + 1)];
		cursor->oper_args_types[0] = types[get_type((typescode & 0xC0) >> 6)];
		cursor->oper_args_types[1] = types[get_type((typescode & 0x30) >> 4)];
		cursor->oper_args_types[2] = types[get_type((typescode & 0xC) >> 2)];
	}
	else
		cursor->oper_args_types[0] = cursor->oper->args_types[0];
}
