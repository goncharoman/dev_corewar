/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:40:15 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/10 06:22:52 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

static void	get_name(t_token *token, t_program *program)
{
	if (token->type != STR)
		token_error(token);
	if (!(program->name = ft_strdup(token->value)))
		term(STR_MEMALLOC_ERR_MSG);
	if (ft_strlen(token->value) > PROG_NAME_LENGTH)
		program_error(PROGRAM_NAME_FAIL_MSG);
}

static void	get_comment(t_token *token, t_program *program)
{
	if (token->type != STR)
		token_error(token);
	if (!(program->comment = ft_strdup(token->value)))
		term(STR_MEMALLOC_ERR_MSG);
	if (ft_strlen(token->value) > COMMENT_LENGTH)
		program_error(PROGRAN_COMMENT_FAIL_MSG);
}

void		get_program_info(t_list **head_lst, t_program *program)
{
	t_token	*token;

	while ((!program->name || !program->comment) && *head_lst)
	{
		token = next_token(head_lst);
		if (!program->name && token->type == CMD &&
			is_cmd(token->value, NAME_CMD_STRING))
		{
			get_name(next_token(head_lst), program);
			if ((next_token(head_lst))->type != ENDLN)
				token_error(token);
		}
		else if (!program->comment && token->type == CMD &&
			is_cmd(token->value, COMMENT_CMD_STRING))
		{
			get_comment(next_token(head_lst), program);
			if ((next_token(head_lst))->type != ENDLN)
				token_error(token);
		}
		else
			token_error(token);
	}
}
