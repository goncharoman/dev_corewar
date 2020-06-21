/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:28:51 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:28:54 by dschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	translate(const char *filename)
{
	int			fd;
	t_list		*tokens_list;
	t_program	*program;

	if ((fd = open(filename, O_RDONLY)) == -1)
		term(OPEN_INFILE_ERR_MSG);
	tokens_list = NULL;
	program = NULL;
	parse(&tokens_list, fd);
	comp(&tokens_list, &program);
	write_bytecode_file(filename, program);
	del_program(&program);
}
