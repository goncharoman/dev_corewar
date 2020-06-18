/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:28:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 22:35:13 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static void	set_cursors(t_vm *vm)
{
	uint32_t	pc;
	int			i;

	pc = 0;
	i = 0;
	while (i < vm->players_num)
	{
		add_cursor(&(vm->cursors), create_cursor(vm->players[i++], pc));
		pc += MEM_SIZE / vm->players_num;
		vm->cursors_count++;
	}
}

static void	place_in_arena(t_vm *vm)
{
	int			i;
	uint32_t	offset;

	i = 0;
	offset = 0;
	while (i < vm->players_num)
	{
		ft_memcpy(&(vm->arena[offset]), vm->players[i]->code,
			(size_t)vm->players[i]->code_size);
		offset += MEM_SIZE / vm->players_num;
		i++;
	}
}

static void	set_vm_players(t_vm *vm)
{
	uint32_t	index;

	if (!vm->tmp_players_lst || ft_lstlen(vm->tmp_players_lst) > MAX_PLAYERS)
		error(vm, !vm->tmp_players_lst ?
			MIN_PLAYERS_ERR_MSG : MAX_PLAYERS_ERR_MSG);
	index = 1;
	while (vm->tmp_players_lst && index <= MAX_PLAYERS)
	{
		if (!(vm->players[index - 1] = \
				next_player(&vm->tmp_players_lst, index)))
		{
			remove_vm(vm);
			print_help();
		}
		vm->players_num++;
		index++;
	}
}

static void	parse_args(t_vm *vm, char **argv)
{
	int8_t	ret;

	while (*argv)
	{
		ret = 0;
		if (!ft_strcmp(*argv, "-dump"))
			ret = set_dump(vm, *(argv + 1));
		else if (!ft_strcmp(*argv, "-a"))
			ret = set_aff(vm);
		else if (!ft_strcmp(*argv, "-l"))
			ret = set_loglevel(vm, *(argv + 1));
		else if (!ft_strcmp(*argv, "-n"))
			ret = set_champ(vm, true, *(argv + 1), *(argv + 2));
		else if (is_filename(*argv, BYTECODE_FILENAME_SUFFIX))
			ret = set_champ(vm, false, NULL, *(argv));
		if (!ret)
		{
			remove_vm(vm);
			print_help();
		}
		argv += ret;
	}
}

void		set_vm(t_vm *vm, char **argv)
{
	parse_args(vm, argv);
	set_vm_players(vm);
	place_in_arena(vm);
	set_cursors(vm);
}
