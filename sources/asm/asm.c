/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:45:32 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 02:16:10 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		main(int argc, char **argv)
{
	errno = 0;
	if (argc == 2 && is_filename(argv[1], ASM_FILENAME_SUFFIX))
		translate(argv[1]);
	else
		print_help();
	return (0);
}
