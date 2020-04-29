/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:50:26 by ujyzene           #+#    #+#             */
/*   Updated: 2020/04/29 23:45:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_comp.h>

t_label	*create_label(char *name, unsigned position)
{
	t_label *label;

	if (!(label = (t_label*)ft_memalloc(sizeof(t_label))))
		exit(1);
	if (!(label->name = ft_strdup(name)))
		exit(1);
	label->init_position = position;
	label->calls = NULL;
	return (label);
}

void	add_label(t_list **labels, t_label *label)
{
	ft_lstappend(labels, ft_lst(label, sizeof(t_label)));
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
