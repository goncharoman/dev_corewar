/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:50:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 15:10:37 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	print_help(void)
{
	ft_printf("Usage: ./corewar [-a] [-dump nbr_cycles] [-s N] [-l log_lavel]");
	ft_printf(" [[-n number champion1.cor] ...\n");
	ft_printf("\t-a - Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("\t-dump nbr_cycles - Dumps memory after N cycles then exits\n");
	ft_printf("\t-l log_lavel - Logging levels, can be added together to ");
	ft_printf("enable several\n");
	ft_printf("\t\t- 0 - Show only essentials\n");
	ft_printf("\t\t- 1 - Show lives\n");
	ft_printf("\t\t- 2 - Show cycles\n");
	ft_printf("\t\t- 4 - Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t- 8 - Show deaths\n");
	ft_printf("\t\t- 16 - Show PC movements (Except for jumps)\n");
	ft_printf("\t-n number - Sets the number of the next player\n");
	exit(1);
}
