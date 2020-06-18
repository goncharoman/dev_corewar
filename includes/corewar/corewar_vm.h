/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:13:04 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/17 20:29:07 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H
# include <corewar.h>

# define LOG_LIVES		1
# define LOG_CYULES		2
# define LOG_OPER		4
# define LOG_DEATHS		8
# define LOG_MOVE		16

t_vm		*create_vm();
void		set_vm(t_vm *vm, char **argv);
void		remove_vm(t_vm *vm);

int8_t		set_dump(t_vm *vm, char *value);
int8_t		set_champ(t_vm *vm, t_bool set_id, char *value, char *champ_name);
int8_t		set_loglevel(t_vm *vm, char *value);
int8_t		set_aff(t_vm *vm);

void		run(t_vm *vm);
void		next_oper(t_vm *vm, t_cursor *cursor);
void		exec_oper(t_vm *vm, t_cursor *cursor);
int32_t		get_arg(uint8_t *mem, t_cursor *cursor, uint8_t index);

t_bool		is_int(char *s);
int32_t		mem_addr(int32_t addr);
uint32_t	type_size(uint8_t type, uint8_t t_dir_size);
int32_t		bcode_to_int(uint8_t *mem, int32_t addr, int32_t size);
void		write_int(uint8_t *mem, int32_t addr, uint32_t size, int32_t value);

t_bool		valid_args(t_vm *vm, t_cursor *cursor);

int32_t		get_byte(uint8_t *mem, uint32_t addr);
int32_t		get_value(uint8_t *mem, uint32_t addr, uint8_t size);
int32_t		get_avalue(uint8_t *mem, t_cursor *cursor, uint32_t *offset,
			uint8_t index);
int32_t		get_addr(uint8_t *mem, uint32_t addr);
void		cycles_to_die_check(t_vm *vm, int32_t *check_counts,
			int32_t *count);

void		log_pcmove(t_vm *vm, t_cursor *cursor, int32_t offset);
void		log_cycle(uint32_t cycle_count);
void		log_die_cycles(int32_t cycle);
void		log_cursor_death(t_cursor *cursor, int32_t cycles,
			int32_t cycles_to_die);

void		get_types(t_vm *vm, t_cursor *cursor);

void		print_representation(t_player **players);
void		print_winner(t_vm *vm);
#endif
