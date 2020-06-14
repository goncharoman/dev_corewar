/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:56:35 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/14 21:57:43 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void print_token(t_token *token)
{
	static int	n = 0;
	const char *dict[] = {
		"CMD",
		"STR",
		"LBL",
		"OPR",
		"REG",
		"DIR",
		"DIRL",
		"IND",
		"INDL",
		"SEP",
		"ENDLN",
		"END"
		};


	printf("%03d [%03d, %03d] (%5s)   %s\n", n++,
													token->row,
													token->col,
													dict[(int)token->type],
													token->value);
}

void	print_tokens(t_list **tokens)
{
	t_list *current;

	if (tokens)
	{
		if (*tokens)
		{
			current = *tokens;
			while (current)
			{
				print_token((t_token*)current->content);
				current = current->next;
			}
		}
	}
}

void	translate(const char *filename)
{
	int			fd;
	t_list		*tokens_list;
	t_program	*program;

	if ((fd = open(filename, O_RDONLY)) == -1)
		term(OPEN_INFILE_ERR_MSG);
	tokens_list = NULL;
	program = NULL;
	parse(&tokens_list, fd);
	print_tokens(&tokens_list);
	comp(&tokens_list, &program);
	write_bytecode_file(filename, program);
	del_program(&program);
	ft_lstdel(&tokens_list, &del_token);
}
