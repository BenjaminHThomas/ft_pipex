#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 11:49:16 by bthomas           #+#    #+#              #
#    Updated: 2024/05/28 14:37:42 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

SRCDIR		= srcs
CFILES		= ft_pipex.c \
			  find_path.c \
			  utils.c \
			  parse_bash.c \
			  init.c \
			  cleanup.c \
			  exec_cmds.c

SRCS		= $(addprefix $(SRCDIR)/,$(CFILES))

OBJDIR		= objs
OBJS		= $(addprefix $(OBJDIR)/,$(CFILES:.c=.o))

CFLAGS		= -Wall -Werror -Wextra -g3
COMPILER	= cc

PRINTF_LIB	= libftprintf.a
PRINTF_DIR	= ./includes/ft_printf
PRINTF		= $(PRINTF_DIR)$(PRINTF_LIB)

LINK		= -L $(PRINTF_DIR) -lftprintf

INCS		= 	-I ./includes/ \
				-I $(PRINTF_DIR)

all: $(OBJDIR) $(PRINTF) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(COMPILER) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(PRINTF):
	@echo "Making printf..."
	@$(MAKE) -sC $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS) $(LINK)

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -sC $(PRINTF_DIR)

fclean: clean
	@echo "Removing program..."
	@rm -rf $(NAME)
	@$(MAKE) fclean -sC $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

