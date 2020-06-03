/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:20:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 18:37:35 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

void	term(const char *message )
{
	if (errno == 0)
		ft_fprintf(2, "%s\n", message);
	else
		perror(message);
	exit(1);
}
