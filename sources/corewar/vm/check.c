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

static void	alive_cursors_head(t_list **cursors, uint32_t cycles,
			int32_t cycles_to_die, t_bool logging)
{
	t_cursor	*cursor;
	t_list		*next;

	while (*cursors)
	{
		cursor = (*cursors)->content;
		if (cycles_to_die <= 0 ||
			cycles - cursor->alive_cycle >= (uint32_t)cycles_to_die)
		{
			next = (*cursors)->next;
			if (logging)
				log_cursor_death(cursor, cycles, cycles_to_die);
			remove_cursor(&cursor);
			free(*cursors);
			*cursors = next;
		}
		else
			break ;
	}
}

static void	alive_cursors(t_list **cursors, uint32_t cycles,
			int32_t cycles_to_die, t_bool logging)
{
	t_cursor	*cursor;
	t_list		*prev;
	t_list		*curr;

	alive_cursors_head(cursors, cycles, cycles_to_die, logging);
	if (!(prev = *cursors))
		return ;
	while ((curr = prev->next))
	{
		cursor = curr->content;
		if (cycles_to_die <= 0 ||
			cycles - cursor->alive_cycle >= (uint32_t)cycles_to_die)
		{
			prev->next = curr->next;
			if (logging)
				log_cursor_death(cursor, cycles, cycles_to_die);
			remove_cursor(&cursor);
			free(curr);
			continue ;
		}
		prev = curr;
	}
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
