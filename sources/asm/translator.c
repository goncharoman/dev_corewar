/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:56:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/02 22:43:28 by ujyzene          ###   ########.fr       */
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
	ft_lstdel(&tokens_list, &del_token);
}
