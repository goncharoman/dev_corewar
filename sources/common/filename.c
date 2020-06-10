/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:45:12 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/08 00:56:22 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

t_bool	is_filename(const char *filename, const char *suffix)
{
	if (filename && suffix)
		return (filename - ft_strstr(filename, suffix) < 0 &&
			!ft_strcmp(ft_strstr(filename, suffix), suffix));
	return (false);
}
