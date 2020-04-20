/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 18:41:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 21:17:06 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	parseln_concat(t_parseln *parseln, char **str)
{
	char *tmp;

	if (!(tmp = ft_strsepjoin(parseln->line, *str, ' ')))
		exit(1);
	/* NOTE: если понадобится использовать строку без пробельных символов, то можно убрать их здесь */
	parseln->row++;
	parseln->size += ft_strlen(*str);
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
	/* NOTE: здесь используем строку без обрамляющих ковычек */
	while (!(endchr = ft_strchr(parseln->line + parseln->col + 1, '\"')) &&
		(err = get_next_line(parseln->fd, &tmp)) > 0)
			parseln_concat(parseln, &tmp);
	if (err == -1)
		terminate("parseln_concat error\n");
	if (err == 0)
		exit(1);
	if (!(token->value = ft_strsub(parseln->line, start,
		endchr - (parseln->line + start))))
		terminate("parse_str error\n");
	parseln->col += endchr - (parseln->line + start) + 1;
	add_token(tokens, token);
}

void		parse_num(t_list **tokens, t_parseln *parseln, t_token *token)
{
	return;
}
