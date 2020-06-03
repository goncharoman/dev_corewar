/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:53:08 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/08 22:29:06 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int8_t	set_dump(t_vm *vm, char *value)
{
	if (!value || !is_int(value))
		return (0);
	if ((vm->dump_cycles = ft_atoi(value)) < 0)
		return (0);
	return (2);
}

int8_t	set_show(t_vm *vm, char *value)
{
	if (!value || !is_int(value))
		return (0);
	if ((vm->show_cycles = ft_atoi(value)) < 0)
		vm->show_cycles = -1;
	return (2);
}

int8_t	set_loglevel(t_vm *vm, char *value)
{
	if (!value || !is_int(value))
		return (0);
	if ((vm->log_lavel = ft_atoi(value)) < 0)
		vm->log_lavel = 0;
	return (2);
}

int8_t	set_aff(t_vm *vm)
{
	vm->aff = true;
	return (1);
}

int8_t	set_champ(t_list **champ_lst, t_bool set_id, char *value,
			char *champ_name)
{
	int			id;
	t_player	*player;

	id = -1;
	if (set_id)
	{
		if (!value || !is_int(value))
			return (0);
		if ((id = ft_atoi(value)) < 1 || id > MAX_PLAYERS ||
			get_player(*champ_lst, id))
			return (0);
	}
	if (!is_filename(champ_name, BYTECODE_FILENAME_SUFFIX))
		return (0);
	add_player(champ_lst, (player = load_player(champ_name)));
	if (set_id)
		player->id = id;
	return (set_id ? 3 : 1);
}
