/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:13:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/23 12:39:59 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TOKEN_H
# define ASM_TOKEN_H
# include <asm.h>

void		add_endtoken(t_list **tokens, t_type type, unsigned row,
			unsigned col);
void		add_token(t_list **tokens, t_token *new_token);
char		*get_value(t_parseln *parseln, unsigned start);
t_token		*next_token(t_list **head);
t_token		*create_token(char *value, t_type type, unsigned row, unsigned col);
void		fill_token(t_token *token, char *value, t_type type, unsigned row,
				unsigned col);
#endif
