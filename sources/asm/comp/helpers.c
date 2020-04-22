/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:40:43 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/22 16:59:37 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_bool	is_cmd(char *arg, const char *command)
{
	if (!arg || !command)
		return (false);
	return (!ft_strcmp(arg, command + 1));
}
