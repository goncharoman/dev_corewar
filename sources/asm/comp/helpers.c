/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:42:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:42:43 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_bool		is_cmd(char *arg, const char *command)
{
	if (!arg || !command)
		return (false);
	return (!ft_strcmp(arg, command + 1));
}

t_bool		is_arg(t_type type)
{
	return ((t_bool)(type == REG || type == DIR || type == DIRL ||
				type == IND || type == INDL));
}

t_bool		reg_nbr_valid(char *value)
{
	int		tmp;

	if ((tmp = ft_atoi((const char*)(value + 1))) > 0 && tmp <= REG_NUMBER)
		return (true);
	return (false);
}

uint8_t		ttype_to_targ(t_type token_type)
{
	if (token_type == DIR || token_type == DIRL)
		return (T_DIR);
	if (token_type == IND || token_type == INDL)
		return (T_IND);
	if (token_type == REG)
		return (T_REG);
	return (0);
}
