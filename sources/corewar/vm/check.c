/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:23:24 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 03:17:29 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static void	reset_players_counters(t_vm *vm)
{
	vm->live_count = 0;
}

static void	alive_cursors(t_list **cursors, uint32_t cycles,
			int32_t cycles_to_die, t_bool logging)
{
	t_list		*tmp;
	t_cursor	*curr;

	if (!(tmp = *cursors))
		return ;
	curr = tmp->content;
	if (cycles_to_die <= 0 ||
		cycles - curr->alive_cycle >= (uint32_t)cycles_to_die)
	{
		if (logging)
			log_cursor_death(curr, cycles, cycles_to_die);
		remove_cursor(&curr);
		tmp->content = NULL;
		*cursors = tmp->next;
		free(tmp);
		alive_cursors(cursors, cycles, cycles_to_die, logging);
	}
	else
		alive_cursors(&(tmp->next), cycles, cycles_to_die, logging);
}

void		cycles_to_die_check(t_vm *vm, int32_t *count, int32_t *check_counts)
{
	(*check_counts)++;
	alive_cursors(&vm->cursors, vm->cycles_count, vm->cycles_to_die,
		vm->log_lavel & LOG_CYULES);
	vm->cursors_count = ft_lstlen(vm->cursors);
	if (*check_counts == MAX_CHECKS || vm->live_count >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->log_lavel & LOG_CYULES)
			log_die_cycles(vm->cycles_to_die);
		*check_counts = 0;
	}
	reset_players_counters(vm);
	*count = 0;
}
