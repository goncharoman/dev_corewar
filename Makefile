# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujyzene <ujyzene@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/16 21:18:57 by ujyzene           #+#    #+#              #
#    Updated: 2020/04/22 16:51:43 by ujyzene          ###   ########.fr        #
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

# PROJECT DIRECTORIES
HEADERS_DIR = ./includes
SOURCES_DIR = ./sources
LIB_DIR = ./lib
TEMP_DIR = ./temp

# ASM
#   headers
ASM_HEADERS_LIST = \
	op.h\
	asm.h \
	test.h
ASM_HEADERS = $(addprefix $(HEADERS_DIR)/, $(ASM_HEADERS_LIST))

#   sources
ASM_SOURCES_MAIN_DIR = asm
ASM_SOURCES_INNER_DIR = $(addprefix $(ASM_SOURCES_MAIN_DIR)/, \
	parser \
	token \
	comp \
	)
ASM_SOURCES = $(addprefix $(ASM_SOURCES_MAIN_DIR)/, \
	asm.c \
	filename.c \
	helpers.c \
	print_help.c \
	translator.c \
	test.c \
 	)
ASM_SOURCES += $(addprefix $(ASM_SOURCES_MAIN_DIR)/parser/, \
	helpers.c \
	skips.c \
	parse.c \
	parse_args.c \
	)
ASM_SOURCES += $(addprefix $(ASM_SOURCES_MAIN_DIR)/token/, \
	add.c \
	helpers.c \
	token.c \
	)
ASM_SOURCES += $(addprefix $(ASM_SOURCES_MAIN_DIR)/comp/, \
	comp.c \
	helpers.c \
	init.c \
	program_info.c \
	)

#   temps
ASM_TEMP_DIRS = $(addprefix $(TEMP_DIR)/, $(ASM_SOURCES_MAIN_DIR))
ASM_TEMP_DIRS += $(addprefix $(TEMP_DIR)/, $(ASM_SOURCES_INNER_DIR))
ASM_TEMP_FILES = $(addprefix $(TEMP_DIR)/, $(ASM_SOURCES:.c=.o))


# COREWAR


# LIB
LIB = $(LIB_DIR)/libft.a
LIB_HEADERS = $(LIB_DIR)/includes
LIB_CONNECT = -lft -L$(LIB_DIR)

# COMP
CC = gcc
FLAGS = -Wall -Wextra -g

INCLUDES = \
	-I$(HEADERS_DIR)\
	-I$(LIB_HEADERS)

.PHONY: all clean fclean re

all: $(ASM_NAME)

$(ASM_NAME): $(LIB) $(TEMP_DIR) $(ASM_TEMP_FILES)
	@ printf "$(CLEARL)\r"
	@ $(CC) $(FLAGS) $(LIB_CONNECT) $(INCLUDES) $(ASM_TEMP_FILES) -o $(ASM_NAME)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(ASM_NAME)$(RESET) $(GREEN)were created!$(RESET)\n" "(corewar)"

$(LIB):
	@ $(MAKE) -sC $(LIB_DIR)

$(TEMP_DIR):
	@ mkdir -p $(ASM_TEMP_DIRS)

$(TEMP_DIR)/%.o : $(SOURCES_DIR)/%.c $(ASM_HEADERS)
	@ $(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)compile:$(RESET) %21s\r" "(corewar)" "$(notdir $@)"

clean:
	@ $(MAKE) -sC $(LIB_DIR) clean
	@ rm -rf $(TEMP_DIR)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(YELLOW)temp files were deleted$(RESET)\n" "(corewar)"

fclean: clean
	@ $(MAKE) -sC $(LIB_DIR) fclean
	@ rm -rf $(ASM_NAME)
	@ printf "$(F_DIM)$(F_BOLD)$(GRAY)%-10s$(RESET) $(F_BOLD)$(ASM_NAME)$(RESET) $(YELLOW)were deleted$(RESET)\n" "(corewar)"

re: fclean all
