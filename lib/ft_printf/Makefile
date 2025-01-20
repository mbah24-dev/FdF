# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 21:18:31 by mbah              #+#    #+#              #
#    Updated: 2025/01/09 18:54:37 by mbah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TESTER_DIR = tester
C_SRC = ft_print_char.c ft_print_string.c ft_print_decimal.c \
		ft_print_hexadec.c ft_print_integer.c ft_print_percent.c \
		ft_print_ptr.c ft_print_udecimal.c ft_printf.c \
		ft_putunbr_fd.c ft_putunbr_base_fd.c
LIBFT = ./libft/libft.a
TEST_EXEC = ft_printf

C_OBJS = $(C_SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I ./
CC = cc

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(C_OBJS) $(LIBFT)
	@echo "libft.a creer avec succees !"
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(C_OBJS)
$(LIBFT):
	@echo "Execution du Makefile de la libft ..."
	$(MAKE) -C ./libft
# exportation du tester
$(TESTER_DIR):
	@echo "exportation du testeur ..."
	@git clone git@github.com:mbah24-dev/tester.git

# Compilation de l'exécutable de test ft_printf
$(TEST_EXEC): $(NAME) $(TESTER_DIR)/ft_printf/main.c
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TESTER_DIR)/ft_printf/main.c $(NAME)
	
all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(C_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -rf $(TESTER_DIR)
	rm -f $(TEST_EXEC)

re: fclean all

.PHONY: all clean fclean re
