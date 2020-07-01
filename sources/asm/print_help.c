/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:44:38 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:44:39 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	print_help(void)
{
	ft_printf("Usage: ./asm <sourcefile.s>\n");
	ft_printf("\t <sourcefile> - source file for assamble to bytecode\n");
	exit(1);
}
