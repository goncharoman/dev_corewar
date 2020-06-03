/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 18:41:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/02 23:54:43 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

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

void		parse_str(t_list **tokens, t_parseln *parseln, t_token *token)
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
		syntax_error(parseln->row, parseln->col);
	if (!(token->value = ft_strsub(parseln->line, start,
		endchr - (parseln->line + start))))
		term(STR_MEMALLOC_ERR_MSG);
	parseln->col += endchr - (parseln->line + start) + 1;
	add_token(tokens, token);
}

void		parse_num(t_list **tokens, t_parseln *parseln, t_token *token)
{
	unsigned start;
	unsigned tmp;

	start = parseln->col;
	parseln->col += *(parseln->line + parseln->col) == '-';
	tmp = parseln->col;
	while (ft_isdigit(*(parseln->line + parseln->col)))
		parseln->col++;
	if ((parseln->col - tmp) &&
		(token->type == DIR || is_spec_smb(*(parseln->line + parseln->col))))
	{
		token->value = get_value(parseln, start);
		add_token(tokens, token);
	}
	else if (token->type != DIR)
	{
		parseln->col = start;
		parse_deep(tokens, parseln, token);
	}
	else
		syntax_error(parseln->row, parseln->col);
}


void		parse_deep(t_list **tokens, t_parseln *parseln, t_token *token)
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
		syntax_error(parseln->row, parseln->col);
}
