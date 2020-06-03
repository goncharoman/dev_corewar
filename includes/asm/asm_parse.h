/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:07:48 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/23 12:39:48 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSE_H
# define ASM_PARSE_H
# include <asm.h>

/* parser/parse.c */

void		parse(t_list **tokens, int fd);

/* parser/parse.c */

void		skip_whitespaces(t_parseln *parseln);
void		skip_comment(t_parseln *parseln);

/* parser/helpers.c */

t_bool		is_whitespace(int c);
t_bool		is_spec_smb(int c);
t_bool 		is_reg(char *value);

/* parser/skips.c */

void		parse_deep(t_list **tokens, t_parseln *parseln, t_token *token);
void		parse_str(t_list **tokens, t_parseln *parseln, t_token *token);
void		parse_num(t_list **tokens, t_parseln *parseln, t_token *token);
#endif
