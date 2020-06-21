/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:27:08 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:27:39 by dschimme         ###   ########.fr       */
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
