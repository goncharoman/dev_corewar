/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 13:55:47 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 22:53:57 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_token.h>

t_token	*next_token(t_list **head)
{
	t_token *token;

	token = NULL;
	if (head && *head)
		token = (*head)->content;
	*head = (*head)->next;
	return (token);
}

t_token	*create_token(char *value, t_type type, unsigned row, unsigned col)
{
	t_token	*token;

	if (!(token = (t_token*)ft_memalloc(sizeof(t_token))))
		term(TOKEN_MEMALLOC_ERR_MSG);
	fill_token(token, value, type, row, col);
	return (token);
}

void	fill_token(t_token *token, char *value, t_type type, unsigned row,					unsigned col)
{
	token->value = value;
	token->type = type;
	token->row = row;
	token->col = col;
}

void	del_token(void *token, size_t size)
{
	if (!token)
		return ;
	ft_strdel(&((t_token*)token)->value);
	free(token);
	size = 0;
}
