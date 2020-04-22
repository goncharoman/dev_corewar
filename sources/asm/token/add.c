/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:02:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/21 18:47:06 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	add_token(t_list **tokens, t_token *new_token)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(new_token, sizeof(t_token))))
		exit(-1);
	ft_lstappend(tokens, tmp);
}

void	add_endtoken(t_list **tokens)
{
	t_list	*tail;
	t_token	*token;

	if ((tail = ft_lsttail(tokens)))
	{
		if ((token = tail->content)->type == ENDLN)
		{
			tail->next = ft_lstnew(create_token(NULL, END, token->row + 1, 0),
				sizeof(t_token));
			if (!(tail->next))
				exit(1);
		}
		return ;
	}
	else
		add_token(tokens, create_token(NULL, END, 0, 0));
}

void	add_endlntoken(t_list **tokens)
{
	t_list	*tail;
	t_token	*token;

	if ((tail = ft_lsttail(tokens)))
	{
		if ((token = tail->content)->type != ENDLN)
		{
			tail->next = ft_lstnew(
				create_token(NULL, ENDLN, token->row, token->row),
				sizeof(t_token));
			if (!(tail->next))
				exit(1);
		}
	}
}
