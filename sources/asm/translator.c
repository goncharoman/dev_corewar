/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:56:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/22 16:54:42 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	translate(const char *filename)
{
	int			fd;
	t_list		*tokens_list;
	t_program	*program;

	if ((fd = open(filename, O_RDONLY)) == -1)
		terminate("open file error");
	tokens_list = NULL;
	program = NULL;
	parse(&tokens_list, fd);
	comp(&tokens_list, &program);
}
