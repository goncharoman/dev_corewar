/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 16:47:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 19:48:15 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_program	*program_init()
{
	t_program	*program;

	if (!(program = (t_program*)ft_memalloc(sizeof(t_program))))
		exit(1);
	program->name = NULL;
	program->comment = NULL;
	program->code = NULL;
	program->position = 0;
	program->size = 0;
	program->labels = NULL;
	return (program);
}

void	increase_code_size(t_program *program)
{
	program->size += CHAMP_MAX_SIZE;
	if (!(program->code = realloc(program->code, (size_t)program->size)))
		exit(1);
}

void	del_program(t_program **program)
{
	if (program && *program)
	{
		ft_strdel(&(*program)->name);
		ft_strdel(&(*program)->comment);
		ft_memdel((void**)&(*program)->code);
		ft_lstdel(&(*program)->labels, &del_label);
		free(*program);
	}
}
