/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:43:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/14 22:00:04 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

static void			parse_chunk(t_list **tokens, t_parseln *parseln)
{
	t_type	type;
	t_token	*token;

	type = get_type(parseln);
	token = create_token(NULL, type, parseln->row,
		parseln->col + (parseln->col == 0));
	if (type == CMD || type == DIRL || type == INDL || type == LBL ||
			type == OPR || type == REG)
		parse_name(parseln, token);
	else if (type == STR)
		parse_str(parseln, token);
	else if (type == DIR || type == IND)
		parse_num(parseln, token);
	add_token(tokens, token);
}

void				parse(t_list **tokens, int fd)
{
	int			err;
	t_parseln	parseln;

	parseln.row = 0;
	parseln.fd = fd;
	while ((err = get_next_line(fd, &(parseln.line))) > 0 && ++parseln.row)
	{
		parseln.size = ft_strlen(parseln.line);
		parseln.col = 0;
		while (*(parseln.line + parseln.col))
		{
			skip_whitespaces(&parseln);
			skip_comment(&parseln);
			if (*(parseln.line + parseln.col))
				parse_chunk(tokens, &parseln);
		}
		if (parseln.size > 0 && parseln.size == parseln.col)
			add_endtoken(tokens, ENDLN, parseln.row, parseln.col + 1);
		ft_strdel(&parseln.line);
	}
	add_endtoken(tokens, END, parseln.row + 1, 0);
	if (err == -1)
		term(READ_FILE_ERR_MSG);
}
