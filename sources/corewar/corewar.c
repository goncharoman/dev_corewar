/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:31:37 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 04:09:15 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		main(int argc, char **argv)
{
	t_vm	*vm;

	errno = 0;
	if (argc >= 2)
	{
		set_vm((vm = create_vm()), argv + 1);
		print_representation((t_player**)vm->players);
		run(vm);
		print_winner(vm);
		remove_vm(vm);
	}
	else
		print_help();
	return (0);
}
