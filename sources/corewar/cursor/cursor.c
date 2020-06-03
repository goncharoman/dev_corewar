/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:50:19 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 05:42:19 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_cursor.h>

t_cursor	*create_cursor(t_player* player, uint32_t pc)
{
	t_cursor		*cursor;
	static uint32_t	id;

	if (!(cursor = (t_cursor*)ft_memalloc(sizeof(t_cursor))))
		term(CURSOR_MEMALLOC_ERR_MSG);
	cursor->id = id++;
	cursor->pc = pc;
	cursor->parent = player;
	cursor->cycles_to_exec = 0;
	cursor->alive_cycle = 0;
	cursor->oper = NULL;
	cursor->jump = false;
	cursor->reg[0] = -(player->id);
	return (cursor);
}

void	add_cursor(t_list **lst, t_cursor *cursor)
{
	t_list	*tmp;

	if (!(tmp = ft_lst((void*)cursor, sizeof(t_cursor))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstadd(lst, tmp);
}

t_cursor	*dup_cursor(t_cursor *cursor, int32_t addr)
{
	t_cursor	*tmp;
	int			i;

	tmp = create_cursor(cursor->parent, mem_addr(cursor->pc + addr));
	i = -1;
	while (++i < REG_NUMBER)
		tmp->reg[i] = cursor->reg[i];
	tmp->jump = cursor->jump;
	tmp->alive_cycle = cursor->alive_cycle;
	return (tmp);
}

void	remove_cursor(t_cursor **cursor)
{
	ft_memdel((void**)cursor);
	*cursor = NULL;
}

void	remove_cursor_from_list(void *cursor, size_t size)
{
	if (size > 0)
		size = 0;
	remove_cursor((t_cursor**)&cursor);
}
