# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 14:29:18 by bthomas           #+#    #+#              #
#    Updated: 2024/05/30 18:43:04 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CFILES			= ft_printf.c \
				  output.c \
				  ft_utils1.c \
				  ft_utils2.c \
				  parse_fmt.c \
				  print_cs.c \
				  print_p.c \
				  print_u.c \
				  print_x.c \
				  print_di.c

OBJ_DIR			= objs
OFILES			= $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

CFLAGS			= -Wall -Werror -Wextra
COMPILER		= cc
AR				= ar
ARFLAGS			= -rcs

LIBFT_LIB		= libft.a
LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/$(LIBFT_LIB)

INCS			= -I $(LIBFT_PATH) -I .

all: $(OBJ_DIR) $(LIBFT) $(NAME)

bonus: all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(COMPILER) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	@echo "Making libft..."
	@$(MAKE) -sC $(LIBFT_PATH)

$(NAME): $(OFILES) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $^

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -sC $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -sC $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
