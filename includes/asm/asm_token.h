/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:13:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 05:34:38 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TOKEN_H
# define ASM_TOKEN_H
# include <asm.h>

void		add_endtoken(t_list **tokens, t_type type, unsigned row,
			unsigned col);
void		add_token(t_list **tokens, t_token *new_token);
t_token		*next_token(t_list **head);
t_token		*create_token(char *value, t_type type, unsigned row, unsigned col);
void		del_token(void *token, size_t size);
#endif
