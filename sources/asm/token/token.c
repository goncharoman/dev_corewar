/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 13:55:47 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 18:21:30 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_token		*create_token(char *value, t_type type, unsigned row, unsigned col)
{
	t_token	*token;

	if (!(token = (t_token*)ft_memalloc(sizeof(t_token))))
		terminate("token error: memory alocation\n");
	fill_token(token, value, type, row, col);
	return (token);
}

void	fill_token(t_token *token, char *value, t_type type, unsigned row, 					unsigned col)
{
	token->value = value;
	token->type = type;
	token->row = row;
	token->col = col;
}
