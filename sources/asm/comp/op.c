/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:11:40 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/23 22:47:56 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>
#include <asm_op.h>

t_op	*get_oper(char *oper_name)
{
	int		i;

	i = 0;
	while (i < OP_NUMS && ft_strcmp(op_tab[i].name, oper_name) != 0)
		i++;
	return (i < OP_NUMS ? (t_op*)(&op_tab[i]) : NULL);
}
