/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:49:56 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/30 00:29:29 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_call	*create_call(t_token *token, unsigned position, unsigned size)
{
	t_call	*call;

	if (!(call = (t_call*)ft_memalloc(sizeof(t_call))))
		exit(1);
	call->row = token->row;
	call->col = token->col - (token->type == DIRL ? 1 : 2);
	call->position = position;
	call->size = size;
	return (call);
}

void	add_call(t_list **calls, t_call *call)
{
	ft_lstappend(calls, ft_lst(call, sizeof(t_call)));
}
