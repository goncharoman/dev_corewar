/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:43:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 22:35:04 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

static t_type		get_type(t_parseln *parseln)
{
	if (*(parseln->line + parseln->col) == SEPARATOR_CHAR && ++(parseln->col))
		return (SEP);
	if (*(parseln->line + parseln->col) == CMD_CHAR && ++(parseln->col))
		return (CMD);
	if (*(parseln->line + parseln->col) == DIRECT_CHAR && ++(parseln->col))
	{
		if (*(parseln->line + parseln->col) == LABEL_CHAR && ++(parseln->col))
			return (DIRL);
		return (DIR);
	}
	if (*(parseln->line + parseln->col) == '\"' && ++(parseln->col))
		return (STR);
	if (*(parseln->line + parseln->col) == LABEL_CHAR && ++(parseln->col))
		return (INDL);
	return (IND);
}

static void			parse_chunk(t_list **tokens, t_parseln *parseln)
{
	t_type	type;
	t_token	*token;

	type = get_type(parseln);
	token = create_token(NULL, type, parseln->row, parseln->col);
	if (type == SEP)
		add_token(tokens, token);
	else if (type == CMD || type == DIRL || type == INDL)
		parse_deep(tokens, parseln, token);
	else if (type == STR)
		parse_str(tokens, parseln, token);
	else
		parse_num(tokens, parseln, token);
}

void					parse(t_list **tokens, int fd)
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
		terminate("error read from file");
}
