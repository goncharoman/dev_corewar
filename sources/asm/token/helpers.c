/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:44:06 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:44:07 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_token.h>

char	*get_value(t_parseln *parseln, unsigned start)
{
	char	*value;

	if (!(value = ft_strsub(parseln->line, start, parseln->col - start)))
		term(STR_MEMALLOC_ERR_MSG);
	return (value);
}
