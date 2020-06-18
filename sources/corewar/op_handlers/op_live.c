/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:31:50 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 16:55:35 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

inline static void	log_live(int32_t id, char *name)
{
	ft_printf("Player %d (%s) is said to be alive\n", id, name);
}

inline static void	log_oper(int32_t id, int32_t value)
{
	ft_printf("P %4d | live %d\n", id + 1, value);
}

uint32_t			handler_live(t_vm *vm, t_cursor *cursor)
{
	uint32_t	offset;
	int32_t		arg;
	t_player	*player;

	player = NULL;
	offset = 1 + (int)cursor->oper->args_typescode;
	arg = get_avalue(vm->arena, cursor, &offset, 0);
	cursor->alive_cycle = vm->cycles_count;
	vm->live_count++;
	if (arg < 0 && (FT_ABS(arg) >= 1 && FT_ABS(arg) <= vm->players_num))
	{
		player = vm->players[FT_ABS(arg) - 1];
		vm->last_alive_player = player;
	}
	if (vm->log_lavel & LOG_OPER)
		log_oper(cursor->id, arg);
	if (vm->log_lavel & LOG_LIVES && player)
		log_live(FT_ABS(arg), player->name);
	return (offset);
}
