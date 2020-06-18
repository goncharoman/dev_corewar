/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_handlers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:51:11 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:52:01 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_HANDLERS_H
# define COREWAR_HANDLERS_H

uint32_t	handler_live(t_vm *vm, t_cursor *cursor);
uint32_t	handler_ld(t_vm *vm, t_cursor *cursor);
uint32_t	handler_st(t_vm *vm, t_cursor *cursor);
uint32_t	handler_add(t_vm *vm, t_cursor *cursor);
uint32_t	handler_sub(t_vm *vm, t_cursor *cursor);
uint32_t	handler_and(t_vm *vm, t_cursor *cursor);
uint32_t	handler_or(t_vm *vm, t_cursor *cursor);
uint32_t	handler_xor(t_vm *vm, t_cursor *cursor);
uint32_t	handler_zjmp(t_vm *vm, t_cursor *cursor);
uint32_t	handler_ldi(t_vm *vm, t_cursor *cursor);
uint32_t	handler_sti(t_vm *vm, t_cursor *cursor);
uint32_t	handler_fork(t_vm *vm, t_cursor *cursor);
uint32_t	handler_lld(t_vm *vm, t_cursor *cursor);
uint32_t	handler_lldi(t_vm *vm, t_cursor *cursor);
uint32_t	handler_lfork(t_vm *vm, t_cursor *cursor);
uint32_t	handler_aff(t_vm *vm, t_cursor *cursor);

#endif
