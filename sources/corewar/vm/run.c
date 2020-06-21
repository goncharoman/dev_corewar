/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:11:45 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/18 20:35:35 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static void	show_arena(uint8_t *arena)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%06p : ", i);
		j = 0;
		while (j < 32)
		{
			ft_printf("%02x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += 32;
	}
}

static void	exec_cursor(t_vm *vm, t_cursor *cursor)
{
	if (cursor->cycles_to_exec == 0)
		next_oper(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
		exec_oper(vm, cursor);
}

static void	next_cycle(t_vm *vm)
{
	t_list	*cursor_lst;

	vm->cycles_count++;
	cursor_lst = vm->cursors;
	if (vm->log_lavel & LOG_CYULES)
		log_cycle(vm->cycles_count);
	while (cursor_lst && vm->cursors_count > 0)
	{
		exec_cursor(vm, (t_cursor*)cursor_lst->content);
		cursor_lst = cursor_lst->next;
	}
}

void		run(t_vm *vm)
{
	int32_t	check_cycles;
	int32_t checks_count;

	check_cycles = 0;
	checks_count = 0;
	while (vm->cursors_count > 0)
	{
		if (vm->dump_cycles != -1
			&& vm->cycles_count == (uint32_t)vm->dump_cycles)
		{
			show_arena(vm->arena);
			remove_vm(vm);
			exit(0);
		}
		next_cycle(vm);
		check_cycles++;
		if (check_cycles == vm->cycles_to_die || vm->cycles_to_die <= 0)
			cycles_to_die_check(vm, &check_cycles, &checks_count);
	}
}
