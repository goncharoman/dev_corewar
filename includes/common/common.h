/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 20:43:09 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/06 00:09:17 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include <libft.h>
# include <errno.h>
# include <stdio.h>

# define ASM_FILENAME_SUFFIX		".s"
# define BYTECODE_FILENAME_SUFFIX	".cor"

void	term(const char *message);
t_bool	is_filename(const char *filename, const char *suffix);

#endif
