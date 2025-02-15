/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:43:55 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:43:56 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	parseln_concat(t_parseln *parseln, char **str)
{
	char *tmp;

	if (!(tmp = ft_strsepjoin(parseln->line, *str, '\n')))
		term(STR_MEMALLOC_ERR_MSG);
	parseln->row++;
	parseln->size += ft_strlen(*str) + 1;
	ft_strdel(&parseln->line);
	ft_strdel(str);
	parseln->line = tmp;
	str = NULL;
}

static char	*get_value(t_parseln *parseln, int start)
{
	char	*value;

	if (!(value = ft_strsub(parseln->line, start, parseln->col - start)))
		term(STR_MEMALLOC_ERR_MSG);
	return (value);
}

t_bool		parse_str(t_parseln *parseln, t_token *token)
{
	char	*endchr;
	char	*tmp;
	int		err;
	int		start;

	start = parseln->col;
	err = 1;
	while (!(endchr = ft_strchr(parseln->line + parseln->col, '\"')) &&
			(err = get_next_line(parseln->fd, &tmp)) > 0)
		parseln_concat(parseln, &tmp);
	if (err == -1)
		term(READ_FILE_ERR_MSG);
	if (err == 0)
		return (err);
	if (!(token->value = ft_strsub(parseln->line, start,
		endchr - (parseln->line + start))))
		term(STR_MEMALLOC_ERR_MSG);
	parseln->col += endchr - (parseln->line + start) + 1;
	return (true);
}

t_bool		parse_num(t_parseln *parseln, t_token *token)
{
	unsigned start;

	start = parseln->col;
	parseln->col += *(parseln->line + parseln->col) == '-';
	while (ft_isdigit(*(parseln->line + parseln->col)))
		parseln->col++;
	if (is_spec_smb(*(parseln->line + parseln->col)))
		token->value = get_value(parseln, start);
	else
		return (false);
	return (true);
}

t_bool		parse_name(t_parseln *parseln, t_token *token)
{
	unsigned start;

	start = parseln->col;
	while (parseln->line[parseln->col] &&
			ft_strchr(LABEL_CHARS, parseln->line[parseln->col]))
		parseln->col++;
	if (parseln->col - start)
	{
		token->value = get_value(parseln, start);
		if (token->type == LBL && parseln->line[parseln->col] == LABEL_CHAR)
			parseln->col++;
	}
	else
		return (false);
	return (true);
}
