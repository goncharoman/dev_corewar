/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_output.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschimme <dschimme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:27:00 by dschimme          #+#    #+#             */
/*   Updated: 2020/06/21 18:27:02 by dschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OUTPUT_H
# define ASM_OUTPUT_H
# include <asm.h>

void	write_bytecode_file(const char *filename, t_program *program);
void	message_success(char *filename);
#endif
