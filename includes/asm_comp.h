/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_comp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:17:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/30 01:36:36 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_COMP_H
# define ASM_COMP_H
# include <asm.h>

/* comp/ */

void		comp(t_list **tokens, t_program **program);
void		get_program_info(t_list **head_lst, t_program *program);
t_bool		is_cmd(char *arg, const char *command);
t_program	*program_init();
void		increase_code_size(t_program *program);
t_op		*get_oper(char *oper_name);

void		get_program_code(t_list **head_lst, t_program *program);
void		write_call(t_op *op, t_token *token, t_program *program);
void		write_num(t_op *op, t_token *token, t_program *program);
void		write_reg(t_token *token, t_program *program);

t_label		*create_label(char *name, unsigned position);
void		add_label(t_list **labels, t_label *label);
t_label		*find_label(t_list **labels, char *name);

t_call		*create_call(t_token *token, unsigned position, unsigned size);
void		add_call(t_list **calls, t_call *call);

void		write_int(t_program *program, uint32_t size, int32_t value);
#endif
