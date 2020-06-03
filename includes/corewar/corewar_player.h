/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_player.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:47:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 03:01:13 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_PLAYER_H
# define COREWAR_PLAYER_H
# include <corewar.h>

t_player	*create_player();
t_player	*load_player(const char *filename);
t_player	*get_player(t_list	*players, uint32_t id);
t_player	*next_player(t_list **lst, uint32_t id);
void		remove_player(t_player **player);

void		read_player(int fd, t_player *player);
void		add_player(t_list **players, t_player *player);
#endif
