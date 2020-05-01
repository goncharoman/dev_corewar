/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_output.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:08:05 by ujyzene           #+#    #+#             */
/*   Updated: 2020/05/01 15:45:41 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OUTPUT_H
# define ASM_OUTPUT_H
# include <asm.h>

void	write_bytecode_file(const char *filename, t_program *program);

#endif
