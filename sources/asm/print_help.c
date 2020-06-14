/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:58:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/14 21:50:49 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	print_help(void)
{
	ft_printf("Usage: ./asm [-a] <sourcefile.s>\n");
	ft_printf("\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output");
}
