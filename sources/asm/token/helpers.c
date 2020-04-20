/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 17:16:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 17:42:51 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*get_value(t_parseln *parseln, unsigned start)
{
	char	*value;

	if (!(value = ft_strsub(parseln->line, start, parseln->col - start)))
		terminate("alocation error: get_token_value");
	return (value);
}
