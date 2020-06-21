/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbins <kbins@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:28:34 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:34:15 by kbins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	print_help(void)
{
	ft_printf("Usage: ./asm <sourcefile.s>\n");
	ft_printf("\t <sourcefile> - source file for assamble to bytecode\n");
	exit(1);
}
