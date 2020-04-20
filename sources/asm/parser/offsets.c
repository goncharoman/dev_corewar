/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:09:36 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 19:12:55 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	offset_whitespaces(t_parseln *parseln)
{
	while (is_whitespace(parseln->line[parseln->col]))
		parseln->col++;
}

void	offset_comment(t_parseln *parseln)
{
	if (parseln->line[parseln->col] == COMMENT_CHAR ||
		parseln->line[parseln->col] == ALT_COMMENT_CHAR)
		while (parseln->line[parseln->col] &&
			parseln->line[parseln->col] != '\n')
			parseln->col++;
}
