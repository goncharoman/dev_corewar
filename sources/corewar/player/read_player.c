/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 01:16:58 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 19:08:58 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_player.h>

static int32_t	int_from_bytecode(uint8_t *value, size_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(*value & 0x80);
	i = 0;
	while (size)
	{
		result += sign ?
			(value[size - 1] ^ 0xFF) << (i++ * 8) :
			value[size - 1] << (i++ * 8);
		size--;
	}
	return (!sign ? result : ~result);
}

static void		read_data(int fd, void **dest, size_t size, t_bool is_string)
{
	int		offset;
	uint8_t	*buff;

	if (!(buff = (uint8_t*)ft_memalloc(size)))
		term(BUFF_MEMALLOC_ERR_MSG);
	if ((offset = read(fd, buff, size)) == -1)
		term(READ_FILE_ERR_MSG);
	if ((size_t)offset < size)
		term(INVALID_FILE_ERR_MSG);
	if (is_string)
	{
		if (!(*dest = ft_strdup((char*)buff)))
			term(STR_MEMALLOC_ERR_MSG);
		ft_memdel((void**)&buff);
	}
	else
		*dest = buff;
}

static int32_t	read_number(int fd)
{
	int		offset;
	uint8_t	*buff;
	int32_t	ret;

	if (!(buff = (uint8_t*)ft_memalloc(4)))
		term(BUFF_MEMALLOC_ERR_MSG);
	if ((offset = read(fd, buff, 4)) == -1)
		term(READ_FILE_ERR_MSG);
	if ((size_t)offset < 4)
		term(INVALID_FILE_ERR_MSG);
	ret = int_from_bytecode(buff, 4);
	ft_memdel((void**)&buff);
	return (ret);
}

void			read_player(int fd, t_player *player)
{
	char buff;

	if (read_number(fd) != COREWAR_EXEC_MAGIC)
		term(INVALID_FILE_ERR_MSG);
	read_data(fd, (void**)&(player->name), PROG_NAME_LENGTH, true);
	if (read_number(fd) != 0)
		term(INVALID_FILE_ERR_MSG);
	if ((player->code_size = read_number(fd)) > CHAMP_MAX_SIZE)
		term(INVALID_FILE_ERR_MSG);
	read_data(fd, (void**)&(player->comment), COMMENT_LENGTH, true);
	if (read_number(fd) != 0)
		term(INVALID_FILE_ERR_MSG);
	read_data(fd, (void**)&(player->code), (size_t)player->code_size, false);
	if (read(fd, &buff, 1) != 0)
		term(INVALID_FILE_ERR_MSG);
}
