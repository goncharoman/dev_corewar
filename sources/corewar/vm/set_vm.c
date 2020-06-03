/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:28:52 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/16 16:52:10 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static void set_cursors(t_vm *vm)
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

static void	set_vm_players(t_vm *vm, t_list **input_champs)
{
	uint32_t	index;

	if (!*input_champs || ft_lstlen(*input_champs) > MAX_PLAYERS)
		term(MAX_PLAYERS_ERR_MSG);
	index = 1;
	while (*input_champs && index <= MAX_PLAYERS)
	{
		if (!(vm->players[index - 1] = next_player(input_champs, index)))
			print_help();
		vm->players_num++;
		index++;
	}
}

static void	parse_args(t_vm *vm, char **argv, t_list **input_champs)
{
	int8_t	ret;

	while (*argv)
	{
		ret = 0;
		if (!ft_strcmp(*argv, "-d") || !ft_strcmp(*argv, "--dump"))
			ret = set_dump(vm, *(argv + 1));
		else if (!ft_strcmp(*argv, "-s") || !ft_strcmp(*argv, "--show"))
			ret = set_show(vm, *(argv + 1));
		else if (!ft_strcmp(*argv, "-a"))
			ret = set_aff(vm);
		else if (!ft_strcmp(*argv, "-l") || !ft_strcmp(*argv, "--log"))
			ret = set_loglevel(vm, *(argv + 1));
		else if (!ft_strcmp(*argv, "-n") || !ft_strcmp(*argv, "--num"))
			ret = set_champ(input_champs, true, *(argv + 1), *(argv + 2));
		else if (is_filename(*argv, BYTECODE_FILENAME_SUFFIX))
			ret = set_champ(input_champs, false, NULL, *(argv));
		if (!ret)
			print_help();
		argv += ret;
	}
}

void	set_vm(t_vm *vm, char **argv)
{
	t_list	*input_champs;

	input_champs = NULL;
	parse_args(vm, argv, &input_champs);
	set_vm_players(vm, &input_champs);
	place_in_arena(vm);
	set_cursors(vm);
}
