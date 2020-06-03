/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:32:02 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/11 00:58:13 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <libft.h>
# include <stdio.h>
# include <fcntl.h>

# include <op.h>
# include <common.h>
# include <corewar_structs.h>
# include <corewar_op.h>
# include <corewar_vm.h>
# include <corewar_errors.h>
# include <corewar_player.h>
# include <corewar_cursor.h>

# define REG_MEM_SIZE	1
# define IND_MEM_SIZE	2
# define DIR_MEM_SIZE	4

void	print_help();
#endif
