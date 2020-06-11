/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:07:37 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/11 23:30:09 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_output.h>

static char		*get_output_filename(const char *filename)
{
	char		*output_filename;
	uint32_t	filename_size;

	filename_size = ft_strstr(filename, ASM_FILENAME_SUFFIX) - filename;
	if (!(output_filename = ft_strnew(filename_size +
			ft_strlen(BYTECODE_FILENAME_SUFFIX))))
		term(STR_MEMALLOC_ERR_MSG);
	ft_strncpy(output_filename, filename, filename_size);
	ft_strcat(output_filename, BYTECODE_FILENAME_SUFFIX);
	return (output_filename);
}

static uint32_t	write_info(uint8_t *buff, char *chunk, uint32_t size)
{
	ft_memcpy(buff, chunk, ft_strlen(chunk));
	return (size);
}

static uint32_t	write_code(uint8_t *buff, uint8_t *code, uint32_t size)
{
	ft_memcpy(buff, code, size);
	return (size);
}

static void		write_bytecode(int fd, t_program *program)
{
	uint8_t		*buff;
	uint32_t	size;
	uint32_t	position;

	buff = NULL;
	size = EXEC_MAGIC_SIZE + PROG_NAME_LENGTH + NULL_SIZE + EXEC_CODE_SIZE +
		COMMENT_LENGTH + NULL_SIZE + program->position;
	if (!(buff = ft_memalloc((size_t)size)))
		term(CBUFF_MEMALLOC_ERR_MSG);
	position = 0;
	position += write_int(buff, position, EXEC_MAGIC_SIZE, COREWAR_EXEC_MAGIC);
	position += write_info(&buff[position], program->name, PROG_NAME_LENGTH);
	position += NULL_SIZE;
	position += write_int(buff, position, EXEC_CODE_SIZE, program->position);
	position += write_info(&buff[position], program->comment, COMMENT_LENGTH);
	position += NULL_SIZE;
	position += write_code(&buff[position], program->code, program->position);
	write(fd, buff, (size_t)size);
	ft_memdel((void**)&buff);
}

void			write_bytecode_file(const char *filename, t_program *program)
{
	char	*output_filename;
	int		fd;

	output_filename = get_output_filename(filename);
	if ((fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, 0664)) == -1)
		term(OPEN_OUTFILE_ERR_MSG);
	write_bytecode(fd, program);
	ft_printf("SUCCESS: bytecode successfully written to %s\n",
		output_filename);
	ft_strdel(&output_filename);
}
