/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skips.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:09:36 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/21 15:34:02 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
