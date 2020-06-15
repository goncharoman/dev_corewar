/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:41:28 by ujyzene           #+#    #+#             */
/*   Updated: 2020/06/15 16:46:39 by ujyzene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERRORS_H
# define ASM_ERRORS_H
# include <asm.h>

/*
** ERROR MESSAGES
*/

# define OPEN_INFILE_ERR_MSG		"ERROR: Can\'t open input file"
# define OPEN_OUTFILE_ERR_MSG		"ERROR: Can\'t open output file"
# define READ_FILE_ERR_MSG			"ERROR: Read error"
# define TOKEN_MEMALLOC_ERR_MSG		"ERROR: Token memory allocation error"
# define LST_MEMALLOC_ERR_MSG		"ERROR: List elem memmory allocation error"
# define STR_MEMALLOC_ERR_MSG		"ERROR: String memory allocation error"
# define CALL_MEMALLOC_ERR_MSG		"ERROR: Call memory allocation error"
# define PROGRAM_MEMALLOC_ERR_MSG	"ERROR: Program memory allocation error"
# define PRGCODE_MEMALLOC_ERR_MSG	"ERROR: Code memory allcocation error"
# define LOST_DATA_ERR_MSG			"ERROR: Lost data error"
# define LABEL_MEMALLOC_ERR_MSG		"ERROR: Label memory allocation error"
# define CBUFF_MEMALLOC_ERR_MSG		"ERROR: Code buffer memory allocation error"

# define PROGRAM_NAME_FAIL_MSG		"FAIL: Wrong program name"
# define PROGRAN_COMMENT_FAIL_MSG	"FAIL: Wrong programm comment"
# define UNEXP_TOKEN_MSG			"Unexpected token"
# define INVALID_ARG_MSG			"Invalid argument"
# define UNDEC_LABEL_MSG			"Undeclared label"

void	print_position(unsigned row, unsigned col);
void	term(const char *message);
void	syntax_error(t_parseln *parseln, t_list **tokens, t_token *token);
void	program_error(t_program **program, const char *message);
void	token_error(t_program **program, t_token *token);
void	invalid_arg(t_program **program, t_token *token, t_op *op, int arg_n);
void	label_error(t_program **program, t_label *label);
#endif
