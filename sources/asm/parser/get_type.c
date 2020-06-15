/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 04:09:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 14:44:37 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_bool	is_reg(char *str_begin, int offset)
{
	char	*value;
	int		i;
	t_bool	resp;

	resp = false;
	if (!(value = ft_strndup((const char*)str_begin, offset)))
		term(STR_MEMALLOC_ERR_MSG);
	if (*value == REG_CHAR && ft_strlen(value) > 1 && ft_strlen(value) <= 3)
	{
		i = 1;
		while (ft_isdigit(value[i]))
			i++;
		resp = !value[i] && ft_atoi(value + 1) > 0 ? true : false;
	}
	ft_strdel(&value);
	return (resp);
}

static t_type	check_next_symbols(t_parseln *parseln)
{
	unsigned	start;
	t_bool		sign;

	start = parseln->col;
	sign = parseln->line[start] == '-' && start++;
	while (ft_isdigit(parseln->line[start]))
		start++;
	if (is_spec_smb(parseln->line[start]))
		return (IND);
	if (sign)
		return (NONE);
	if (parseln->line[start] == LABEL_CHAR)
		return (LBL);
	while (parseln->line[start] && ft_strchr(LABEL_CHARS, parseln->line[start]))
		start++;
	if (parseln->line[start] == LABEL_CHAR)
		return (LBL);
	if (is_reg(parseln->line + parseln->col, start - parseln->col))
		return (REG);
	return (OPR);
}

t_type			get_type(t_parseln *parseln)
{
	if (*(parseln->line + parseln->col) == SEPARATOR_CHAR && ++(parseln->col))
		return (SEP);
	if (*(parseln->line + parseln->col) == CMD_CHAR && ++(parseln->col))
		return (CMD);
	if (*(parseln->line + parseln->col) == DIRECT_CHAR && ++(parseln->col))
	{
		if (*(parseln->line + parseln->col) == LABEL_CHAR && ++(parseln->col))
			return (DIRL);
		return (DIR);
	}
	if (*(parseln->line + parseln->col) == '\"' && ++(parseln->col))
		return (STR);
	if (*(parseln->line + parseln->col) == LABEL_CHAR && ++(parseln->col))
		return (INDL);
	return (check_next_symbols(parseln));
}
