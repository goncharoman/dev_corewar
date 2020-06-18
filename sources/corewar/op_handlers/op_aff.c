/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:10:23 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:55:12 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

uint32_t	handler_aff(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		value;

	offset = 1 + cursor->oper->args_typescode;
	value = get_avalue(vm->arena, cursor, &offset, 0);
	if (vm->aff)
		ft_printf("Aff: %c\n", (char)value);
	return (offset);
}
