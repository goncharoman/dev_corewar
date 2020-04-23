/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:37:54 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/23 22:24:40 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCTS_H
# define ASM_STRUCTS_H
# include <libft.h>

typedef enum	s_type
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
	END
}				t_type;

typedef	struct	s_token
{
	char		*value;
	t_type		type;
	unsigned	row;
	unsigned	col;
}				t_token;

typedef struct	s_parseln
{
	int			fd;
	char		*line;
	unsigned	size;
	unsigned	row;
	unsigned	col;
}				t_parseln;

typedef struct	s_program
{
	char		*name;
	char		*comment;
	uint8_t		*code;
	int32_t		position;
	int32_t		size;
}				t_program;

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_n;
	t_bool		args_typescode;
	uint8_t		args_types[3];
	uint8_t		tdir_size;
}				t_op;

#endif
