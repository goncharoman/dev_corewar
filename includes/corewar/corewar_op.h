/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:03:17 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:41:49 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_H
# define COREWAR_OP_H
# include <corewar.h>

# define OP_NUMS	16

static t_op		g_tab[OP_NUMS] = {
	{
		.name = "live",
		.code = 0x01,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 4,
		.cycles_to_exec = 10,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.tdir_size = 4,
		.cycles_to_exec = 5,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_REG, T_IND | T_REG, 0},
		.tdir_size = 4,
		.cycles_to_exec = 5,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG, T_REG},
		.tdir_size = 4,
		.cycles_to_exec = 10,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG, T_REG},
		.tdir_size = 4,
		.cycles_to_exec = 10,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
		.cycles_to_exec = 6,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
		.cycles_to_exec = 6,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
		.cycles_to_exec = 6,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
		.cycles_to_exec = 20,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.tdir_size = 2,
		.cycles_to_exec = 25,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.tdir_size = 2,
		.cycles_to_exec = 25,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
		.cycles_to_exec = 800,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.tdir_size = 4,
		.cycles_to_exec = 10,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.tdir_size = 2,
		.cycles_to_exec = 50,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
		.cycles_to_exec = 1000,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_n = 1,
		.args_typescode = true,
		.args_types = {T_REG, 0, 0},
		.tdir_size = 4,
		.cycles_to_exec = 2,
	},
};

static uint32_t (*g_handlers[OP_NUMS])(t_vm*, t_cursor*) = {
	&handler_live,
	&handler_ld,
	&handler_st,
	&handler_add,
	&handler_sub,
	&handler_and,
	&handler_or,
	&handler_xor,
	&handler_zjmp,
	&handler_ldi,
	&handler_sti,
	&handler_fork,
	&handler_lld,
	&handler_lldi,
	&handler_lfork,
	&handler_aff,
};
#endif
