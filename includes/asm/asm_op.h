/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:49:03 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 23:22:50 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OP_H
# define ASM_OP_H
# include <asm.h>

# define OP_NUMS	16

const t_op		g_tab[OP_NUMS] = {
	{
		.name = "live",
		.code = 0x01,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 4,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.tdir_size = 4,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_REG, T_IND | T_REG, 0},
		.tdir_size = 4,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG, T_REG},
		.tdir_size = 4,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG, T_REG},
		.tdir_size = 4,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.tdir_size = 4,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.tdir_size = 2,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.tdir_size = 2,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_n = 2,
		.args_typescode = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.tdir_size = 4,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_n = 3,
		.args_typescode = true,
		.args_types = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.tdir_size = 2,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_n = 1,
		.args_typescode = false,
		.args_types = {T_DIR, 0, 0},
		.tdir_size = 2,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_n = 1,
		.args_typescode = true,
		.args_types = {T_REG, 0, 0},
		.tdir_size = 4,
	}
};
#endif
