/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:13:27 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/07 22:46:48 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_player.h>

static t_player	*extract_player(t_list **lst, uint32_t id)
{
	t_player	*player;
	t_list		*curr;
	t_list		*next;

	if (!lst || !(curr = *lst))
		return (NULL);
	if ((player = (t_player*)curr->content)->id == id)
	{
		*lst = (*lst)->next;
		free(curr);
		return (player);
	}
	while ((next = curr->next))
	{
		if ((player = (t_player*)next->content)->id == id)
		{
			curr->next = next->next;
			free(next);
			return (player);
		}
		else
			curr = next;
	}
	return (NULL);
}

t_player		*next_player(t_list **lst, uint32_t id)
{
	t_player	*player;

	if ((player = extract_player(lst, id)))
		return (player);
	else if ((player = extract_player(lst, 0)))
	{
		player->id = id;
		return (player);
	}
	return (NULL);
}

t_player		*get_player(t_list *players, uint32_t id)
{
	if (id >= 1 && id <= MAX_PLAYERS)
	{
		while (players)
		{
			if (((t_player*)players->content)->id == id)
				return (players->content);
			players = players->next;
		}
	}
	return (NULL);
}
