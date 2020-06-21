/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:31:29 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:31:33 by dschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_label	*create_label(char *name, unsigned position)
{
	t_label *label;

	if (!(label = (t_label*)ft_memalloc(sizeof(t_label))))
		term(LABEL_MEMALLOC_ERR_MSG);
	if (!(label->name = ft_strdup(name)))
		term(STR_MEMALLOC_ERR_MSG);
	label->position = position;
	label->calls = NULL;
	return (label);
}

void	add_label(t_list **labels, t_label *label)
{
	t_list	*tmp;

	if (!(tmp = ft_lst(label, sizeof(t_label))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstappend(labels, tmp);
}

t_label	*find_label(t_list **labels, char *name)
{
	t_list	*curr;

	if (labels && *labels)
	{
		curr = *labels;
		while (curr)
		{
			if (ft_strcmp(((t_label*)curr->content)->name, name) == 0)
				return (curr->content);
			curr = curr->next;
		}
	}
	return (NULL);
}

void	del_label(void *label, size_t size)
{
	if (!label)
		return ;
	ft_strdel(&((t_label*)label)->name);
	ft_lstdel(&((t_label*)label)->calls, &del_call);
	if (size != 0)
		size = 0;
	free(label);
}
