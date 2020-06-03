/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:11:45 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 00:45:30 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

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

void	run(t_vm *vm)
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
			// show_arena(vm->arena);
			exit(0);
		}
		else if (vm->show_cycles > 0 && !(vm->cycles_count % vm->show_cycles))
		{
			// show_arena(vm->arena);
			if (ft_getchar() != '\n')
				;
		}
		next_cycle(vm);
		check_cycles++;
		if (check_cycles == vm->cycles_to_die || vm->cycles_to_die <= 0)
			cycles_to_die_check(vm, &check_cycles, &checks_count);
	}
}
