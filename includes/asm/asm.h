/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:39:33 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:39:35 by ujyzene          ###   ########.fr       */
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

# define EXEC_MAGIC_SIZE	4
# define NULL_SIZE			4
# define EXEC_CODE_SIZE		4

# include <op.h>
# include <common.h>
# include <asm_structs.h>
# include <asm_parse.h>
# include <asm_token.h>
# include <asm_comp.h>
# include <asm_output.h>
# include <asm_errors.h>

void			translate(const char *filename);
void			print_help();
#endif
