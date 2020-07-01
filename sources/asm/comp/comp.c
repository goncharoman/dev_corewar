/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:42:29 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:42:30 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

void	comp(t_list **tokens, t_program **program)
{
	t_list	*bgn_token;

	if (!*tokens)
		term(LOST_DATA_ERR_MSG);
	if (!*program)
		*program = program_init();
	bgn_token = *tokens;
	(*program)->tokens_list = *tokens;
	get_program_info(&bgn_token, *program);
	get_program_code(&bgn_token, *program);
	fill_calls(*program);
}
