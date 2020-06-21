/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbins <kbins@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:29:18 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:34:05 by kbins            ###   ########.fr       */
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
