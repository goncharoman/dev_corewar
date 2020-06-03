/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:02:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/02 21:05:09 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_token.h>

void	add_token(t_list **tokens, t_token *new_token)
{
	t_list	*tmp;

	if (!(tmp = ft_lst(new_token, sizeof(t_token))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstappend(tokens, tmp);
}

void	add_endtoken(t_list **tokens, t_type type, unsigned row, unsigned col)
{
	t_list	*tail;
	t_token	*token;

	if ((tail = ft_lsttail(tokens)) && (type == END || type == ENDLN))
	{
		if (((token = tail->content)->type == ENDLN && type == END) ||
			(token->type != ENDLN && type == ENDLN))
		{
			if (!(tail->next = ft_lst(create_token(NULL, type, row, col),
				sizeof(t_token))))
			if (!(tail->next))
				term(LST_MEMALLOC_ERR_MSG);
		}
	}
	else
		if (type == END)
			add_token(tokens, create_token(NULL, END, 0, 0));
}
