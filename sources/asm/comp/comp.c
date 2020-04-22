/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:30:59 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/22 16:52:47 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	comp(t_list **tokens, t_program **program)
{
	t_list	*bgn_token;

	if (!*tokens)
		exit(1);
	if (!*program)
		*program = program_init();
	bgn_token = *tokens;
	get_program_info(&bgn_token, *program);
}
