/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:41:30 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/20 19:35:50 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include <op.h>
#endif

# define REG_CHAR			'r'
# define CMD_CHAR			'.'
# define NEWLINE_CHAR		'\n'
# define ALT_COMMENT_CHAR	';'
# define ASM_FILENAME_SUFFIX		".s"
# define BYTECODE_FILENAME_SUFFIX	".cor"

typedef struct	s_parseln
{
	int			fd;
	char		*line;
	unsigned	size;
	unsigned	row;
	unsigned	col;
}				t_parseln;

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

t_token		*create_token(char *value, t_type type, unsigned row, unsigned col);
void		fill_token(t_token *token, char *value, t_type type, unsigned row,
				unsigned col);
void		add_token(t_list **tokens, t_token *new_token);
char		*get_value(t_parseln *parseln, unsigned start);

void			parse(t_list **tokens, int fd);
void			offset_whitespaces(t_parseln *parseln);
void			offset_comment(t_parseln *parseln);

t_bool			is_whitespace(int c);
t_bool			is_spec_smb(int c);
t_bool 			is_reg(char *value);

t_bool	is_filename(const char *filename, const char *suffix);

void	translate(const char *filename);

int		print_help();

void	terminate(char *message);

void	parse_str(t_list **tokens, t_parseln *parseln, t_token *token);
void	parse_num(t_list **tokens, t_parseln *parseln, t_token *token);
