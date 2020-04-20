/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:02:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 18:21:02 by ujyzene          ###   ########.fr       */
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
