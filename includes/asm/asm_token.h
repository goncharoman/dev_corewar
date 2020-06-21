/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:27:29 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:27:33 by dschimme         ###   ########.fr       */
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
