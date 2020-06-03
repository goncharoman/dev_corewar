/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:03:42 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 05:17:12 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCTS_H
# define COREWAR_STRUCTS_H

# include <corewar.h>

typedef struct s_vm		t_vm;
typedef struct s_player	t_player;
typedef	struct s_cursor	t_cursor;
typedef struct s_op		t_op;

struct s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_n;
	t_bool		args_typescode;
	uint8_t		args_types[3];
	uint8_t		tdir_size;
	uint32_t	cycles_to_exec;
};

struct s_cursor
{
	uint32_t	id;
	uint32_t	pc;
	uint32_t	cycles_to_exec;
	int32_t		reg[REG_NUMBER];
	t_op		*oper;
	uint8_t		oper_args_types[3];
	t_player	*parent;
	t_bool		jump;
	uint32_t	alive_cycle;
};

struct	s_vm
{
	uint8_t		arena[MEM_SIZE];
	int32_t		players_num;
	t_player	*players[MAX_PLAYERS];
	uint32_t	cursors_count;
	t_list		*cursors;
	uint32_t	cycles_count;
	int32_t		cycles_to_die;
	t_player	*last_alive_player;
	uint32_t	live_count;
	int32_t		dump_cycles;
	int32_t		show_cycles;
	t_bool		aff;
	int8_t		log_lavel;
};

struct	s_player
{
	uint32_t	id;
	char		*name;
	char		*comment;
	int32_t		code_size;
	uint8_t		*code;
	t_cursor	*cursor;
};

#endif
