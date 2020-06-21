/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:53:08 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/18 21:31:25 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int8_t			set_dump(t_vm *vm, char *value)
{
	if (!value || !is_int(value))
		return (0);
	if ((vm->dump_cycles = ft_atoi(value)) < 0)
		return (0);
	return (2);
}

int8_t			set_loglevel(t_vm *vm, char *value)
{
	if (!value || !is_int(value))
		return (0);
	if ((vm->log_lavel = ft_atoi(value)) < 0)
		vm->log_lavel = 0;
	return (2);
}

int8_t			set_aff(t_vm *vm)
{
	vm->aff = true;
	return (1);
}

static t_player	*load_player(t_vm *vm, int fd)
{
	t_player	*player;

	player = create_player();
	if (!(read_player(fd, player)))
	{
		remove_player(&player);
		error(vm, INVALID_FILE_ERR_MSG);
	}
	if (!player->code || player->code_size == 0)
		remove_player_warning(&player, WARNING);
	return (player);
}

int8_t			set_champ(t_vm *vm, t_bool set_id, char *value,
					char *champ_name)
{
	int			id;
	t_player	*player;
	int			fd;

	id = -1;
	if (set_id)
	{
		if (!value || !is_int(value))
			return (0);
		if ((id = ft_atoi(value)) < 1 || id > MAX_PLAYERS ||
			get_player(vm->tmp_players_lst, id))
			return (0);
	}
	if (!is_filename(champ_name, BYTECODE_FILENAME_SUFFIX))
		return (0);
	if ((fd = open(champ_name, O_RDONLY)) < 0)
		term(OPEN_PLAYER_ERR_MSG);
	add_player(&vm->tmp_players_lst, (player = load_player(vm, fd)));
	if (set_id && player)
		player->id = id;
	return (set_id ? 3 : 1);
}
