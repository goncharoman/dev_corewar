/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:10:11 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/18 23:48:44 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	print_representation(t_player **players)
{
	int32_t	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < MAX_PLAYERS && players[i])
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			players[i]->id, players[i]->code_size,
			players[i]->name, players[i]->comment);
		i++;
	}
}

void	print_winner(t_vm *vm)
{
	if (vm->last_alive_player)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->last_alive_player->id, vm->last_alive_player->name);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->players[vm->players_num - 1]->id,
			vm->players[vm->players_num - 1]->name);
}
