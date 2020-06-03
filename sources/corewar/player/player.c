/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:46:33 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 03:27:20 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_player.h>

t_player	*create_player()
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

t_player	*load_player(const char *filename)
{
	t_player	*player;
	int			fd;
	int			*tmp;

	player = create_player();
	tmp = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		term(OPEN_PLAYER_ERR_MSG);
	read_player(fd, player);
	return (player);
}

void	add_player(t_list **players, t_player *player)
{
	t_list	*tmp;

	if (!(tmp = ft_lst(player, sizeof(t_player))))
		term(LST_MEMALLOC_ERR_MSG);
	ft_lstappend(players, tmp);
}

void	remove_player(t_player **player)
{
	ft_strdel(&((*player)->name));
	ft_strdel(&((*player)->comment));
	ft_memdel((void**)&((*player)->code));
	ft_memdel((void**)player);
	*player = NULL;
}
