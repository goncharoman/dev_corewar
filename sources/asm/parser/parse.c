/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:43:50 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:43:50 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

static void			parse_chunk(t_list **tokens, t_parseln *parseln)
{
	t_type	type;
	t_token	*token;
	t_bool	err;

	err = true;
	type = get_type(parseln);
	token = create_token(NULL, type, parseln->row, parseln->col);
	if (type == CMD || type == DIRL || type == INDL || type == LBL ||
			type == OPR || type == REG)
		err = parse_name(parseln, token);
	else if (type == STR)
		err = parse_str(parseln, token);
	else if (type == DIR || type == IND)
		err = parse_num(parseln, token);
	else if (type == NONE)
		err = false;
	if (!err)
		lexical_error(parseln, tokens, token);
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
			add_endtoken(tokens, ENDLN, parseln.row, parseln.col);
		ft_strdel(&parseln.line);
	}
	add_endtoken(tokens, END, parseln.row + 1, 0);
	if (err == -1)
		term(READ_FILE_ERR_MSG);
}
