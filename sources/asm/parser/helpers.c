/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:19:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 18:36:26 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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

t_bool is_reg(char *value)
{
	int	i;

	if (*value == REG_CHAR && ft_strlen(value) > 1 && ft_strlen(value) <= 3)
	{
		i = 0;
		value++;
		while (ft_isdigit(value[i]))
			i++;
		return (!value[i] && ft_atoi(value) > 0 ? true : false);
	}
	return (false);
}
