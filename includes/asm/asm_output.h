/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_output.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:40:14 by ujyzene           #+#    #+#             */
/*   Updated: 2020/07/01 22:40:15 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OUTPUT_H
# define ASM_OUTPUT_H
# include <asm.h>

void	write_bytecode_file(const char *filename, t_program *program);
void	message_success(char *filename);
#endif
