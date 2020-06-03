/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_comp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:17:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 19:45:54 by ujyzene          ###   ########.fr       */
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
void		del_program(t_program **program);
void		increase_code_size(t_program *program);
t_op		*get_oper(char *oper_name);

void		get_program_code(t_list **head_lst, t_program *program);
void		proc_call(t_op *op, t_token *token, t_program *program, int arg);
void		proc_num(t_op *op, t_token *token, t_program *program);
void		proc_reg(t_token *token, t_program *program);

t_label		*create_label(char *name, unsigned position);
void		add_label(t_list **labels, t_label *label);
t_label		*find_label(t_list **labels, char *name);
void		del_label(void *label,size_t size);

t_call		*create_call(t_token *token, int32_t position,
			int32_t instrct_position, uint32_t size);
void		add_call(t_list **calls, t_call *call);
void		del_call(void *call, size_t size);

void		write_num(t_program *program, uint8_t size, int32_t value);
uint32_t	write_int(uint8_t *code, uint32_t position, uint8_t size,
			int32_t value);

void		fill_calls(t_program *program);
#endif
