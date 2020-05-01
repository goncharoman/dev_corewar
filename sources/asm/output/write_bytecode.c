/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:07:37 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 18:42:51 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm_output.h>

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

	size = EXEC_MAGIC_SIZE + PROG_NAME_LENGTH + NULL_SIZE + EXEC_CODE_SIZE +
		COMMENT_LENGTH + NULL_SIZE + program->position;
	if (!(buff = ft_memalloc((size_t)size)))
		exit(1);
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
	int 	fd;

	output_filename = get_output_filename(filename);
	if ((fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, 0664)) == -1)
		exit(1);
	write_bytecode(fd, program);
	ft_strdel(&output_filename);
}
