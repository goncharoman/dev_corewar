/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:58:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/14 22:09:33 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	print_help(void)
{
	ft_printf("Usage: ./asm <sourcefile.s>\n");
	ft_printf("\t <sourcefile> - source file for assamble to bytecode\n");
	exit(1);
}
