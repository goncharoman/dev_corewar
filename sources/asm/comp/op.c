/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbins <kbins@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:31:37 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:35:00 by kbins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>
#include <asm_op.h>

t_op	*get_oper(char *oper_name)
{
	int		i;

	i = 0;
	while (i < OP_NUMS && ft_strcmp(g_tab[i].name, oper_name) != 0)
		i++;
	return (i < OP_NUMS ? (t_op*)(&g_tab[i]) : NULL);
}
