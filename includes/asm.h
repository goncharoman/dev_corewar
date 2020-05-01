/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:41:30 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 16:50:56 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <libft.h>

# define REG_CHAR			'r'
# define CMD_CHAR			'.'
# define NEWLINE_CHAR		'\n'
# define ALT_COMMENT_CHAR	';'
# define ASM_FILENAME_SUFFIX		".s"
# define BYTECODE_FILENAME_SUFFIX	".cor"

# define EXEC_MAGIC_SIZE	4
# define NULL_SIZE			4
# define EXEC_CODE_SIZE		4


# include <op.h>
# include <asm_structs.h>
# include <asm_parse.h>
# include <asm_token.h>
# include <asm_comp.h>
# include <asm_output.h>
# include <test.h>

t_bool		is_filename(const char *filename, const char *suffix);
char		*get_output_filename(const char *filename);
void		translate(const char *filename);
int			print_help();
void		terminate(char *message);
#endif



