/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 01:48:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 02:12:27 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCTS_H
# define ASM_STRUCTS_H
# include <libft.h>
# include <stdlib.h>

typedef enum e_type			t_type;
typedef struct s_token		t_token;
typedef struct s_parseln	t_parseln;
typedef struct s_program	t_program;
typedef struct s_op			t_op;
typedef struct s_call		t_call;
typedef struct s_label		t_label;

enum			e_type
{
	CMD,
	STR,
	LBL,
	OPR,
	REG,
	DIR,
	DIRL,
	IND,
	INDL,
	SEP,
	ENDLN,
	END,
};

struct			s_token
{
	char		*value;
	t_type		type;
	unsigned	row;
	unsigned	col;
};

struct			s_parseln
{
	int			fd;
	char		*line;
	unsigned	size;
	unsigned	row;
	unsigned	col;
};

struct			s_program
{
	char		*name;
	char		*comment;
	uint8_t		*code;
	uint32_t	position;
	uint32_t	size;
	t_list		*labels;
};

struct			s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_n;
	t_bool		args_typescode;
	uint8_t		args_types[3];
	uint8_t		tdir_size;
};

struct			s_call
{
	unsigned	row;
	unsigned	col;
	int32_t		position;
	int32_t		instrct_position;
	uint32_t	size;
};

struct			s_label
{
	char		*name;
	int32_t		position;
	t_list		*calls;
};

#endif
