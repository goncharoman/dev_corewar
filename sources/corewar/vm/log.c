/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:23:36 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/18 21:07:16 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void log_pcmove(t_vm *vm, t_cursor *cursor, int32_t offset)
{
	int32_t	i;

	ft_printf("ADV %d (%#06x -> %#06x) ", offset, cursor->pc,
		cursor->pc + offset);
	i = 0;
	while (i < offset)
		ft_printf("%02x ", vm->arena[mem_addr(cursor->pc + i++)]);
	ft_printf("\n");
}

void	log_cycle(uint32_t cycle_count)
{
	ft_printf("It is now cycle %d\n", cycle_count);
}

void	log_die_cycles(int32_t cycle)
{
	ft_printf("Cycle to die is now %d\n", cycle);
}

void	log_cursor_death(t_cursor *cursor, int32_t cycles,
		int32_t cycles_to_die)
{
	ft_printf("Process %d hasn't lived for %u cycles (CTD %d)\n",
		cursor->id + 1, cycles - cursor->alive_cycle, cycles_to_die);
}
