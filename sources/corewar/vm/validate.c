/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:14:47 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 05:26:33 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static t_bool	reg_nbr_valid(int32_t value)
{
	return ((t_bool)(value >= 1 && value <= REG_NUMBER));
}

t_bool			valid_args(t_vm *vm, t_cursor *cursor)
{
	int8_t	i;
	int32_t	offset;

	i = 0;
	offset = 1 + (int)cursor->oper->args_typescode;
	while (i < cursor->oper->args_n)
	{
		if (!(cursor->oper_args_types[i] & cursor->oper->args_types[i]))
			return (false);
		if (cursor->oper_args_types[i] == T_REG)
		{
			if (!reg_nbr_valid(get_byte(vm->arena, cursor->pc + offset)))
				return (false);
		}
		offset += type_size(cursor->oper_args_types[i],
			cursor->oper->tdir_size);
		i++;
	}
	return (true);
}
