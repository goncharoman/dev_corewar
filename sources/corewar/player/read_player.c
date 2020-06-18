/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 01:16:58 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 22:13:50 by ujyzene          ###   ########.fr       */
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

	if (size == 0)
		return ;
	if (!(buff = (uint8_t*)ft_memalloc(size + 1)))
		term(BUFF_MEMALLOC_ERR_MSG);
	if ((offset = read(fd, buff, size)) == -1)
		term(READ_FILE_ERR_MSG);
	if ((size_t)offset < size)
	{
		ft_memdel((void**)&buff);
		return ;
	}
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

	ret = -1;
	if (!(buff = (uint8_t*)ft_memalloc(4)))
		term(BUFF_MEMALLOC_ERR_MSG);
	if ((offset = read(fd, buff, 4)) == -1)
		term(READ_FILE_ERR_MSG);
	if ((size_t)offset == 4)
		ret = int_from_bytecode(buff, 4);
	ft_memdel((void**)&buff);
	return (ret);
}

t_bool			read_player(int fd, t_player *player)
{
	char	buff;

	if (read_number(fd) != COREWAR_EXEC_MAGIC)
		return (false);
	read_data(fd, (void**)&(player->name), PROG_NAME_LENGTH, true);
	if (!player->name)
		return (false);
	if (read_number(fd) != 0)
		return (false);
	if ((player->code_size = read_number(fd)) > CHAMP_MAX_SIZE ||
		player->code_size < 0)
		return (false);
	read_data(fd, (void**)&(player->comment), COMMENT_LENGTH, true);
	if (!player->comment)
		return (false);
	if (read_number(fd) != 0)
		return (false);
	read_data(fd, (void**)&(player->code), (size_t)player->code_size, false);
	if (read(fd, &buff, 1) != 0)
		return (false);
	return (true);
}
