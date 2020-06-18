/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 16:47:16 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 15:53:34 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_program	*program_init(void)
{
	t_program	*program;

	if (!(program = (t_program*)ft_memalloc(sizeof(t_program))))
		term(PROGRAM_MEMALLOC_ERR_MSG);
	program->name = NULL;
	program->comment = NULL;
	program->code = NULL;
	program->position = 0;
	program->size = 0;
	program->labels = NULL;
	program->tokens_list = NULL;
	return (program);
}

void		increase_code_size(t_program *program)
{
	if (program->size == 0)
	{
		program->size += CHAMP_MAX_SIZE;
		if (!(program->code = ft_memalloc((size_t)program->size)))
			term(PRGCODE_MEMALLOC_ERR_MSG);
	}
	else
	{
		program->size += CHAMP_MAX_SIZE;
		if (!(program->code = realloc(program->code, (size_t)program->size)))
			term(PRGCODE_MEMALLOC_ERR_MSG);
	}
}

void		del_program(t_program **program)
{
	if (program && *program)
	{
		ft_strdel(&(*program)->name);
		ft_strdel(&(*program)->comment);
		ft_memdel((void**)&(*program)->code);
		ft_lstdel(&(*program)->labels, &del_label);
		ft_lstdel(&(*program)->tokens_list, &del_token);
		free(*program);
	}
}
