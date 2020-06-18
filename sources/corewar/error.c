/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:22:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 22:43:03 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_errors.h>

void	error(t_vm *vm, const char *message)
{
	ft_fprintf(2, "%s\n", message);
	remove_vm(vm);
	exit(1);
}

void	remove_player_warning(t_player **player, const char *message)
{
	ft_fprintf(2, "%s: Player %s (%s) ", message,
					(*player)->name, (*player)->comment);
	ft_fprintf(2, "has empty code and was deleted from competition\n");
	remove_player(player);
}
