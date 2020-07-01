/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:40:23 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:40:24 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_PARSE_H
# define ASM_PARSE_H
# include <asm.h>

void		parse(t_list **tokens, int fd);
void		skip_whitespaces(t_parseln *parseln);
void		skip_comment(t_parseln *parseln);
t_bool		is_whitespace(int c);
t_bool		is_spec_smb(int c);
t_type		get_type(t_parseln *parseln);
t_bool		parse_name(t_parseln *parseln, t_token *token);
t_bool		parse_str(t_parseln *parseln, t_token *token);
t_bool		parse_num(t_parseln *parseln, t_token *token);

#endif
