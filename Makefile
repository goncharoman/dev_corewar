# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/16 21:18:57 by ujyzene           #+#    #+#              #
#    Updated: 2020/05/18 20:36:06 by ujyzene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
F_DIM	= \033[2m
F_BOLD	= \033[1m
GRAY	= \033[38;5;253m
ITALIC	= \e[3m
RED		= \033[38;5;160m
GREEN	= \033[38;5;35m
YELLOW	= \033[38;5;184m
RESET	= \e[0m
BLUE	= \033[38;5;32m

# ESC
CLEARL	= \e[2K
CLEARS	= \e[2J
CLEARUP	= \e[1J

# MAIN
ASM_NAME = asm
COREWAR_NAME = corewar
COMMON_NAME = common

# PROJECT DIRECTORIES
HEADERS_DIR = ./includes
SOURCES_DIR = ./sources
LIB_DIR = ./lib
TEMP_DIR = ./temp

# ASM
#   headers
ASM_HEADERS_DIR = $(HEADERS_DIR)/$(ASM_NAME)
ASM_HEADERS = $(addprefix $(ASM_HEADERS_DIR)/, \
	asm.h \
	asm_structs.h \
	asm_comp.h \
	asm_parse.h \
	asm_token.h \
	asm_output.h \
	asm_errors.h \
	)

#   sources
ASM_SOURCES_INNER_DIR = $(addprefix $(ASM_NAME)/, \
	parser \
	token \
	comp \
	output \
	errors \
	)
ASM_SOURCES = $(addprefix $(ASM_NAME)/, \
	asm.c \
	print_help.c \
	translator.c \
 	)
ASM_SOURCES += $(addprefix $(ASM_NAME)/parser/, \
	helpers.c \
	skips.c \
	parse.c \
	parse_args.c \
	)
ASM_SOURCES += $(addprefix $(ASM_NAME)/token/, \
	add.c \
	helpers.c \
	token.c \
	)
ASM_SOURCES += $(addprefix $(ASM_NAME)/comp/, \
	call.c \
	comp.c \
	fill_calls.c \
	helpers.c \
	label.c \
	op.c \
	program.c \
	program_args.c \
	program_info.c \
	program_instrct.c \
	)
ASM_SOURCES += $(addprefix $(ASM_NAME)/output/, \
	write_bytecode.c \
	)
ASM_SOURCES += $(addprefix $(ASM_NAME)/errors/, \
	errors.c \
	)

#   temps
ASM_TEMP_DIRS = $(addprefix $(TEMP_DIR)/, $(ASM_NAME))
ASM_TEMP_DIRS += $(addprefix $(TEMP_DIR)/, $(ASM_SOURCES_INNER_DIR))
ASM_TEMP_FILES = $(addprefix $(TEMP_DIR)/, $(ASM_SOURCES:.c=.o))

#   includes
ASM_INCLUDES = -I$(ASM_HEADERS_DIR)


# COREWAR
#   headers
COREWAR_HEADERS_DIR = $(HEADERS_DIR)/$(COREWAR_NAME)
COREWAR_HEADERS = $(addprefix $(COREWAR_HEADERS_DIR)/, \
	corewar.h \
	corewar_errors.h \
	corewar_structs.h \
	corewar_vm.h \
	corewar_player.h \
	corewar_cursor.h \
	corewar_op.h \
	)

#   sources
COREWAR_SOURCES_INNER_DIR = $(addprefix $(COREWAR_NAME)/, \
	vm \
	player \
	cursor \
	op_handlers \
	)
COREWAR_SOURCES = $(addprefix $(COREWAR_NAME)/, \
	corewar.c \
	help.c \
 	)
COREWAR_SOURCES += $(addprefix $(COREWAR_NAME)/vm/, \
	args.c \
	check.c \
	exec.c \
	helpers.c \
	mode.c \
	run.c \
	set_vm.c \
	validate.c \
	types.c \
	vm.c \
	log.c \
	print.c \
 	)
# COREWAR_SOURCES += $(addprefix $(COREWAR_NAME)/errors/, \
#  	)
COREWAR_SOURCES += $(addprefix $(COREWAR_NAME)/player/, \
	player.c \
	read_player.c \
	get_player.c \
	)
COREWAR_SOURCES += $(addprefix $(COREWAR_NAME)/cursor/, \
	cursor.c \
	)
COREWAR_SOURCES += $(addprefix $(COREWAR_NAME)/op_handlers/, \
	op_add.c \
	op_aff.c \
	op_and.c \
	op_fork.c \
	op_ld.c \
	op_ldi.c \
	op_lfork.c \
	op_live.c \
	op_lld.c \
	op_lldi.c \
	op_or.c \
	op_st.c \
	op_sti.c \
	op_sub.c \
	op_xor.c \
	op_zjmp.c \
	)

#   temps
COREWAR_TEMP_DIRS = $(addprefix $(TEMP_DIR)/, $(COREWAR_NAME))
COREWAR_TEMP_DIRS += $(addprefix $(TEMP_DIR)/, $(COREWAR_SOURCES_INNER_DIR))
COREWAR_TEMP_FILES = $(addprefix $(TEMP_DIR)/, $(COREWAR_SOURCES:.c=.o))

#   includes
COREWAR_INCLUDES = -I$(COREWAR_HEADERS_DIR)

# COMMON
#   headers
COMMON_HEADERS_DIR = $(HEADERS_DIR)/$(COMMON_NAME)
COMMON_HEADERS = $(addprefix $(COMMON_HEADERS_DIR)/, \
	op.h \
	common.h \
	)

#   sources
COMMON_SOURCES = $(addprefix $(COMMON_NAME)/, \
	term.c \
	filename.c \
 	)

#   temps
COMMON_TEMP_DIR = $(addprefix $(TEMP_DIR)/, $(COMMON_NAME))
COMMON_TEMP_FILES = $(addprefix $(TEMP_DIR)/, $(COMMON_SOURCES:.c=.o))

#   includes
COMMON_INCLUDES = -I$(COMMON_HEADERS_DIR)

# LIB
LIB = $(LIB_DIR)/libft.a
LIB_HEADERS = $(LIB_DIR)/includes
LIB_CONNECT = -lft -L$(LIB_DIR)

# COMP
CC = gcc
FLAGS = -Wall -Wextra -g

INCLUDES = \
	-I$(LIB_HEADERS) \
	-I$(HEADERS_DIR) \
	-I$(COMMON_HEADERS_DIR)

.PHONY: all clean fclean re

all: $(LIB) $(TEMP_DIR) $(COMMON_NAME) $(ASM_NAME) $(COREWAR_NAME)

$(LIB):
	@ $(MAKE) -sC $(LIB_DIR)

$(TEMP_DIR):
	@ mkdir -p $(ASM_TEMP_DIRS)
	@ mkdir -p $(COREWAR_TEMP_DIRS)
	@ mkdir -p $(COMMON_TEMP_DIR)

$(COMMON_NAME): $(COMMON_TEMP_FILES) $(COMMON_HEADERS)

$(TEMP_DIR)/$(COMMON_NAME)/%.o : $(SOURCES_DIR)/$(COMMON_NAME)/%.c $(COMMON_HEADERS)
	@ $(CC) $(FLAGS) $(INCLUDES) $(COMMON_INCLUDES) -c $< -o $@
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)compile:$(RESET) %21s\r" "($(COMMON_NAME))" "$(notdir $@)"

$(ASM_NAME): $(ASM_TEMP_FILES)
	@ printf "$(CLEARL)\r"
	@ $(CC) $(FLAGS) $(INCLUDES) $(COMMON_TEMP_FILES) $(ASM_TEMP_FILES) -o $(ASM_NAME) $(LIB_CONNECT)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(ASM_NAME)$(RESET) $(GREEN)were created!$(RESET)\n" "(corewar)"

$(TEMP_DIR)/$(ASM_NAME)/%.o : $(SOURCES_DIR)/$(ASM_NAME)/%.c $(ASM_HEADERS) $(COMMON_TEMP_FILES) $(COMMON_HEADERS)
	@ $(CC) $(FLAGS) $(INCLUDES) $(ASM_INCLUDES) -c $< -o $@
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)compile:$(RESET) %21s\r" "($(ASM_NAME))" "$(notdir $@)"

$(COREWAR_NAME): $(COREWAR_TEMP_FILES)
	@ printf "$(CLEARL)\r"
	@ $(CC) $(FLAGS) $(INCLUDES) $(COMMON_TEMP_FILES) $(COREWAR_TEMP_FILES) -o $(COREWAR_NAME) $(LIB_CONNECT)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(COREWAR_NAME)$(RESET) $(GREEN)were created!$(RESET)\n" "(corewar)"

$(TEMP_DIR)/$(COREWAR_NAME)/%.o : $(SOURCES_DIR)/$(COREWAR_NAME)/%.c $(COREWAR_HEADERS) $(COMMON_TEMP_FILES) $(COMMON_HEADERS)
	@ $(CC) $(FLAGS) $(INCLUDES) $(COREWAR_INCLUDES) -c $< -o $@
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)compile:$(RESET) %21s\r" "($(COREWAR_NAME))" "$(notdir $@)"

clean:
	@ $(MAKE) -sC $(LIB_DIR) clean
	@ rm -rf $(TEMP_DIR)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)temp files were deleted$(RESET)\n" "(corewar)"

fclean: clean
	@ $(MAKE) -sC $(LIB_DIR) fclean
	@ rm -rf $(ASM_NAME)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(ASM_NAME)$(RESET) $(YELLOW)were deleted$(RESET)\n" "(corewar)"

re: fclean all
