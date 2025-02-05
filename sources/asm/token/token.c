/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:44:12 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:44:13 by ujyzene          ###   ########.fr       */
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
	token->value = value;
	token->type = type;
	token->row = row == 0 ? 1 : row;
	token->col = col + 1 - (type == DIRL);
	return (token);
}

void	del_token(void *token, size_t size)
{
	if (!token)
		return ;
	ft_strdel(&((t_token*)token)->value);
	free(token);
	if (size != 0)
		size = 0;
}
