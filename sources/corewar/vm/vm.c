/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:12:24 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 15:10:26 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

t_vm		*create_vm(void)
{
	t_vm	*vm;

	if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
		term(VM_MEMALLOC_ERR_MSG);
	vm->cursors = NULL;
	vm->cursors_count = 0;
	vm->dump_cycles = -1;
	vm->aff = false;
	vm->log_lavel = 0;
	vm->players_num = 0;
	vm->cycles_count = 0;
	vm->live_count = 0;
	vm->last_alive_player = NULL;
	vm->cycles_to_die = CYCLE_TO_DIE;
	return (vm);
}

static void	remove_players_array(t_player **players, int32_t size)
{
	int i;

	i = 0;
	while (i < size)
		remove_player(&players[i++]);
}

void		remove_vm(t_vm *vm)
{
	if (vm->cursors && vm->cursors_count > 0)
		ft_lstdel(&(vm->cursors), &remove_cursor_from_list);
	if (vm->players_num > 0)
		remove_players_array(vm->players, vm->players_num);
	ft_memdel((void**)&vm);
}
