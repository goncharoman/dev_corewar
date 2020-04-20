/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:43:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 21:08:36 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_type		get_type(t_parseln *parseln)
{
	if (*(parseln->line + parseln->col) == SEPARATOR_CHAR && ++parseln->col)
		return (SEP);
	if (*(parseln->line + parseln->col) == NEWLINE_CHAR && ++parseln->col)
		return (ENDLN);
	if (*(parseln->line + parseln->col) == CMD_CHAR && ++parseln->col)
		return (CMD);
	if (*(parseln->line + parseln->col) == DIRECT_CHAR && ++parseln->col)
	{
		if (*(parseln->line + parseln->col) == LABEL_CHAR && ++parseln->col)
			return (DIRL);
		return (DIR);
	}
	if (*(parseln->line + parseln->col) == '\"' && ++parseln->col)
		return (STR);
	if (*(parseln->line + parseln->col) == LABEL_CHAR && ++parseln->col)
		return (INDL);
	return (IND);
}

static void		parse_deep(t_list **tokens, t_parseln *parseln, t_token *token)
{
	unsigned start;

	start = parseln->col;
	while (parseln->line[parseln->col] &&
			ft_strchr(LABEL_CHARS, parseln->line[parseln->col]))
		parseln->col++;
	if (parseln->col - start)
	{
		token->value = get_value(parseln, start);
		if (parseln->line[parseln->col] == LABEL_CHAR && parseln->col++)
			token->type = LBL;
		else if (is_spec_smb(parseln->line[parseln->col]))
			if (token->type == IND)
				token->type = is_reg(token->value) ? REG : OPR;
		add_token(tokens, token);
	}
	else
		exit(1);
}

static void	parse_chunk(t_list **tokens, t_parseln *parseln)
{
	t_type	type;
	t_token	*token;

	type = get_type(parseln);
	token = create_token(NULL, type, parseln->row, parseln->col);
	/* TODO: нужно обрабатывать конец строки по другому!
		ВОЗМОЖНО:
			отслеживать parseln->col и parseln->size */
	if (type == SEP || type == ENDLN)
		add_token(tokens, token);
	else if (type == CMD || type == DIRL || type == INDL)
		parse_deep(tokens, parseln, token);
	else if (type == STR)
		parse_str(tokens, parseln, token);
	else
		parse_num(tokens, parseln, token);
}

void	parse(t_list **tokens, int fd)
{
	int			err;
	t_parseln	parseln;

	parseln.row = 0;
	parseln.fd = fd;
	while ((err = get_next_line(fd, &(parseln.line)) > 0 &&
		(parseln.row++ >= 0)))
	{
		parseln.size = ft_strlen(parseln.line);
		parseln.col = 0;
		while (*(parseln.line + parseln.col))
		{
			offset_whitespaces(&parseln);
			offset_comment(&parseln);
			parse_chunk(tokens, &parseln);
		}
	}
	ft_strdel(&(parseln.line));
	if (err == -1)
		terminate("error read from file");
}
