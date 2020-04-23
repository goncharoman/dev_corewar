/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:02:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/23 12:20:55 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_token.h>

void	add_token(t_list **tokens, t_token *new_token)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(new_token, sizeof(t_token))))
		exit(-1);
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
			if (!(tail->next = ft_lstnew(create_token(NULL, type, row, col),
				sizeof(t_token))))
			if (!(tail->next))
				exit(1);
		}
	}
	else
		if (type == END)
			add_token(tokens, create_token(NULL, END, 0, 0));
}
