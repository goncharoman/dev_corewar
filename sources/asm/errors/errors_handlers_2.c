/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handlers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 00:50:46 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/20 01:04:22 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_errors.h>

void	reg_error(t_program **program, t_token *token)
{
	ft_fprintf(2, "[%u, %u]\t%s %s (%s)\n", token->row, token->col,
		WRONG_REG_NBR_MSG, token->value + 1, token->value);
	del_program(program);
	exit(1);
}
