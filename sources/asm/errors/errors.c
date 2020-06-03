/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:13:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/15 14:39:21 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_errors.h>

void	syntax_error(unsigned row, unsigned col)
{
	ft_fprintf(2, "[%d, %d]\tSyntax error\n", row, col);
	exit(1);
}

void	program_error(const char *message)
{
	ft_fprintf(2, "%s\n", message);
	exit(1);
}

void	token_error(t_token *token)
{
	ft_fprintf(2, "[%d, %d]\t%s \"%s\"\n", token->row, token->col,
		UNEXP_TOKEN_MSG, token->value);
	exit(1);
}

void	invalid_arg(t_token *token)
{
	ft_fprintf(2, "[%d, %d]\t%s \"%s\"\n", token->row, token->col,
		INVALID_ARG_MSG, token->value);
	exit(1);
}

void	label_error(t_label *label)
{
	t_call	*call;

	if (label->calls && (call = label->calls->content))
		ft_fprintf(2, "[%d, %d]\t", call->row, call->col);
	ft_fprintf(2, "%s \"%s\"\n", UNDEC_LABEL_MSG, label->name);
	exit(1);
}
