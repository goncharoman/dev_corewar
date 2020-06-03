/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:05:25 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/18 20:04:14 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static uint32_t	instruct_offset(t_cursor *cursor)
{
	int			i;
	uint32_t	offset;

	i = 0;
	offset = 1 + (int)cursor->oper->args_typescode;
	while (i < cursor->oper->args_n)
		offset += type_size(cursor->oper_args_types[i++],
			cursor->oper->tdir_size);
	return (offset);
}

static void		move_cursor(t_cursor *cursor, int32_t offset)
{
	cursor->pc += offset;
	cursor->pc = mem_addr(cursor->pc);
	ft_bzero(cursor->oper_args_types, 3);
}

void	next_oper(t_vm *vm, t_cursor *cursor)
{
	int	code;

	code = vm->arena[cursor->pc];
	if (code >= 0x01 && code <= 0x10)
	{
		cursor->oper = &op_tab[code - 1];
		cursor->cycles_to_exec = cursor->oper->cycles_to_exec;
	}
}

void	exec_oper(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;

	offset = 1;
	if (cursor->oper)
	{
		get_types(vm, cursor);
		if (valid_args(vm, cursor))
			offset = op_handlers[cursor->oper->code - 1](vm, cursor);
		else
			offset = instruct_offset(cursor);
		if (vm->log_lavel & LOG_MOVE && offset)
			log_pcmove(vm, cursor, offset);
	}
	move_cursor(cursor, offset);
	cursor->oper = NULL;
}
