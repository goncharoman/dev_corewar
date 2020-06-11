/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:49:56 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 22:20:37 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_call	*create_call(t_token *token, int32_t position,
			int32_t instrct_position, uint32_t size)
{
	t_call	*call;

	if (!(call = (t_call*)ft_memalloc(sizeof(t_call))))
		term(CALL_MEMALLOC_ERR_MSG);
	call->row = token->row;
	call->col = token->col - (token->type == DIRL ? 1 : 2);
	call->position = position;
	call->instrct_position = instrct_position;
	call->size = size;
	return (call);
}

void	add_call(t_list **calls, t_call *call)
{
	t_list	*tmp;

	if (!(tmp = ft_lst(call, sizeof(t_call))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstappend(calls, tmp);
}

void	del_call(void *call, size_t size)
{
	if (call)
		free(call);
	size = 0;
}
