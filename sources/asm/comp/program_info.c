/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:40:15 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/22 17:17:25 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void get_name(t_token *token, t_program *program)
{
	if (token->type != STR)
		exit(1);
	if (!(program->name = ft_strdup(token->value)))
		terminate("error");
	if (ft_strlen(token->value) > PROG_NAME_LENGTH)
		exit(1);
}

static void get_comment(t_token *token, t_program *program)
{
	if (token->type != STR)
		exit(1);
	if (!(program->comment = ft_strdup(token->value)))
		terminate("error");
	if (ft_strlen(token->value) > COMMENT_LENGTH)
		exit(1);
}

void	get_program_info(t_list **head_lst, t_program *program)
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
				exit(1);
		}
		else if (!program->comment && token->type == CMD &&
			is_cmd(token->value, COMMENT_CMD_STRING))
		{
			get_comment(next_token(head_lst), program);
			if ((next_token(head_lst))->type != ENDLN)
				exit(1);
		}
		else
			exit(1);
	}
}
