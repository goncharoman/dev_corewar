/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_calls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:31:09 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:31:15 by dschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

static void	fillwith_this(t_program *program, t_label *label)
{
	t_call	*call;
	t_list	*tmp_lst;

	if (label->position == -1)
		label_error(&program, label);
	tmp_lst = label->calls;
	while (tmp_lst)
	{
		call = tmp_lst->content;
		write_int(program->code,
					call->position,
					call->size, call->size == 2 ? \
						(int16_t)(label->position - call->instrct_position) :
							label->position - call->instrct_position);
		tmp_lst = tmp_lst->next;
	}
}

void		fill_calls(t_program *program)
{
	t_list	*tmp;

	tmp = program->labels;
	while (tmp)
	{
		fillwith_this(program, tmp->content);
		tmp = tmp->next;
	}
}
