/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:45:12 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 16:05:38 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_bool	is_filename(const char *filename, const char *suffix)
{
	if (filename && suffix)
		return (filename - ft_strstr(filename, suffix) < 0 &&
			!ft_strcmp(ft_strstr(filename, suffix), suffix));
	return (false);
}

char	*get_output_filename(const char *filename)
{
	char		*output_filename;
	uint32_t	filename_size;

	filename_size = ft_strstr(filename, ASM_FILENAME_SUFFIX) - filename;
	if (!(output_filename = ft_strnew(filename_size +
			ft_strlen(BYTECODE_FILENAME_SUFFIX))))
		exit(1);
	ft_strncpy(output_filename, filename, filename_size);
	ft_strcat(output_filename, BYTECODE_FILENAME_SUFFIX);
	return (output_filename);
}
