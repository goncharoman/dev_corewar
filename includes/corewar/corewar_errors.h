/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:17:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/19 04:22:42 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ERRORS_H
# define COREWAR_ERRORS_H

# include <corewar.h>
# include <errno.h>

# define VM_MEMALLOC_ERR_MSG		"ERROR: VM memory allocation error"
# define PLAYER_MEMALLOC_ERR_MSG	"ERROR: Player memory allocation error"
# define ARENA_MEMALLOC_ERR_MSG		"ERROR: Arena memory allocation error"
# define OPEN_PLAYER_ERR_MSG		"ERROR: Can\'t open player file"
# define BUFF_MEMALLOC_ERR_MSG		"ERROR: Buffer memory allocation error"
# define READ_FILE_ERR_MSG			"ERROR: Can\'t read player file"
# define INVALID_FILE_ERR_MSG		"ERROR: Invalid player file"
# define LST_MEMALLOC_ERR_MSG		"ERROR: List elem memmory allocation error"
# define STR_MEMALLOC_ERR_MSG		"ERROR: String memory allocation error"
# define MAX_PLAYERS_ERR_MSG		"ERROR: Too much players"
# define CURSOR_MEMALLOC_ERR_MSG	"ERROR: Cursor memmory allocation error"

#endif
