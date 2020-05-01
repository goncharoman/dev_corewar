/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:30:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 15:04:51 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

void	comp(t_list **tokens, t_program **program)
{
	t_list	*bgn_token;

	if (!*tokens)
		exit(1);
	if (!*program)
		*program = program_init();
	bgn_token = *tokens;
	get_program_info(&bgn_token, *program);
	get_program_code(&bgn_token, *program);
	fill_calls(*program);
}
