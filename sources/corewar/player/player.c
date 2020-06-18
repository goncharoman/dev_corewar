/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:46:33 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 22:20:55 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_player.h>

t_player	*create_player(void)
{
	t_player	*player;

	if (!(player = (t_player*)ft_memalloc(sizeof(t_player))))
		term(PLAYER_MEMALLOC_ERR_MSG);
	player->id = 0;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = -1;
	player->code = NULL;
	return (player);
}

void		add_player(t_list **players, t_player *player)
{
	t_list	*tmp;

	if (player == NULL)
		return ;
	if (!(tmp = ft_lst(player, sizeof(t_player))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstappend(players, tmp);
}

void		remove_player(t_player **player)
{
	ft_strdel(&((*player)->name));
	ft_strdel(&((*player)->comment));
	ft_memdel((void**)&((*player)->code));
	ft_memdel((void**)player);
	*player = NULL;
}

void		remove_player_from_lst(void *content, size_t content_size)
{
	if (content_size != 0)
		content_size = 0;
	remove_player((t_player**)&content);
}
