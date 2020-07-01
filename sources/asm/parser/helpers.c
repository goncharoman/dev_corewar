/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:43:44 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:43:45 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_parse.h>

t_bool	is_whitespace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

t_bool	is_spec_smb(int c)
{
	return (c == '\0' ||
			c == '\n' ||
			c == '\"' ||
			c == DIRECT_CHAR ||
			c == SEPARATOR_CHAR ||
			c == COMMENT_CHAR ||
			c == ALT_COMMENT_CHAR ||
			is_whitespace(c));
}

void	skip_whitespaces(t_parseln *parseln)
{
	while (is_whitespace(parseln->line[parseln->col]))
		parseln->col++;
}

void	skip_comment(t_parseln *parseln)
{
	if (parseln->line[parseln->col] == COMMENT_CHAR ||
		parseln->line[parseln->col] == ALT_COMMENT_CHAR)
		while (parseln->line[parseln->col])
			parseln->col++;
}
