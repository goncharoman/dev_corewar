/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:13:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 02:51:11 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_errors.h>

void	lexical_error(t_parseln *parseln, t_list **tokens, t_token *token)
{
	int err;

	ft_fprintf(2, "[%u, %u]\tLexical error\n", token->row, token->col);
	ft_lstdel(tokens, &del_token);
	del_token(token, sizeof(t_token));
	ft_strdel(&parseln->line);
	while ((err = get_next_line(parseln->fd, &parseln->line)) > 0)
		ft_strdel(&parseln->line);
	exit(1);
}

void	program_error(t_program **program, const char *message)
{
	ft_fprintf(2, "%s\n", message);
	del_program(program);
	exit(1);
}

void	token_error(t_program **program, t_token *token)
{
	const char *type_names[] = {"NONE", "CMD", "STR", "LBL", "OPR", "REG",
			"DIR", "DIRL", "IND", "INDL", "SEP", "ENDLN", "END"};

	ft_fprintf(2, "[%u, %u]\t%s \"%s\" (%s)\n", token->row, token->col,
		UNEXP_TOKEN_MSG, token->value ? token->value : "",
		type_names[token->type]);
	del_program(program);
	exit(1);
}

void	invalid_arg(t_program **program, t_token *token, t_op *op, int arg_n)
{
	ft_fprintf(2, "[%u, %u]\t%s (%s) for %s at %d position\n",
				token->row, token->col,
				INVALID_ARG_MSG,
				token->value,
				op->name,
				arg_n + 1);
	del_program(program);
	exit(1);
}

void	label_error(t_program **program, t_label *label)
{
	t_call	*call;

	if (label->calls && (call = label->calls->content))
		ft_fprintf(2, "[%u, %u]\t", call->row, call->col);
	ft_fprintf(2, "%s \"%s\"\n", UNDEC_LABEL_MSG, label->name);
	del_program(program);
	exit(1);
}
