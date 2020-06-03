/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_cursor.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 19:40:45 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 03:16:59 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_CURSOR_H
# define COREWAR_CURSOR_H

# include <corewar.h>

t_cursor	*create_cursor(t_player *player, uint32_t pc);
void		add_cursor(t_list **lst, t_cursor *cursor);
t_cursor	*dup_cursor(t_cursor *cursor, int32_t addr);
void		remove_cursor(t_cursor **cursor);
void		remove_cursor_from_list(void *cursor, size_t size);

#endif
