/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:43:09 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 23:06:19 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <libft.h>
# include <errno.h>
# include <stdio.h>

# define ASM_FILENAME_SUFFIX		".s"
# define BYTECODE_FILENAME_SUFFIX	".cor"

void	term(const char *message);
t_bool	is_filename(const char *filename, const char *suffix);

#endif
