# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 19:11:38 by mbah              #+#    #+#              #
#    Updated: 2025/01/23 17:06:06 by mbah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      ?= fdf
CC         = cc
DIR        = src
FT_PRINTF  = ./lib/ft_printf/libftprintf.a  # Path to the libftprintf.a
LIBFT      = ./lib/ft_printf/libft/libft.a
INC        = inc
CFLAGS     = -Wall -Werror -Wextra -I $(INC)
LDFLAGS    = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -L./lib/ft_printf -lftprintf -lm  # Added -lm for math library
HEADER     = $(INC)/get_next_line.h $(INC)/FdF.h $(INC)/FdF_utils.h
SRC        = $(DIR)/app/utility/gnl/get_next_line_utils.c $(DIR)/app/utility/gnl/get_next_line.c $(DIR)/main.c \
			 $(DIR)/app/utility/app.draw_line.c $(DIR)/app/utility/app.draw_pixel.c $(DIR)/app/utility/app.make_colors.c \
			 $(DIR)/app/utility/map/app.map.init_point.c $(DIR)/app/utility/map/app.map.parse_map.c \
			 $(DIR)/app/utility/app.convert_base.c $(DIR)/app/core/app.core.draw_map.c
			  

OBJS       = $(SRC:.c=.o)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT) # Depend on libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(FT_PRINTF):  # Specify how to build libftprintf.a
	@$(MAKE) -C ./lib/ft_printf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) clean -C ./lib/ft_printf
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./lib/ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
