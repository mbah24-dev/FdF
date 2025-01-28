# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 16:26:17 by mbah              #+#    #+#              #
#    Updated: 2025/01/27 23:36:01 by mbah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      ?= fdf
CC         = cc
DIR        = src
INC        = inc
LIBFT	   = lib/libft/
LIBFT_A    = $(addprefix $(LIBFT), libft.a)
CFLAGS     = -Wall -Werror -Wextra -I $(INC)
HEADER     = $(INC)/libft.h $(INC)/get_next_line.h $(INC)/fdf.h $(INC)/macos_keys.h $(INC)/linux_keys.h $(INC)/mlx.h
SRC        = $(DIR)/app/core/app.draw_map_and_menu.c $(DIR)/app/core/app.projection.c $(DIR)/app/core/app.xiaolin_wu_line_utils.c \
			 $(DIR)/app/core/app.xiaolin_wu_line.c $(DIR)/app/core/app.hooks_controls.c $(DIR)/app/core/app.keyboard_event.c \
			 $(DIR)/app/core/app.parse_map.c $(DIR)/app/core/app.mouse_event.c $(DIR)/app/utility/app.convert_base.c \
			 $(DIR)/app/utility/app.fdf_utils.c $(DIR)/main.c $(DIR)/app/utility/app.color_utils.c \
			 lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c
OBJS       = $(SRC:.c=.o)

# Détection du système d'exploitation
UNAME      = $(shell uname)
ifeq ($(UNAME), Darwin) # macOS
    MLX        = minilibx_macos/       # Dossier MinilibX pour macOS
    MLX_A      = $(addprefix $(MLX), libmlx.a)
    MLX_FLAGS  = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME), Linux) # Linux
    MLX        = minilibx_linux/ # Dossier MinilibX pour Linux
    MLX_A      = $(addprefix $(MLX), libmlx_Linux.a)
    MLX_FLAGS  = -L$(MLX) -lmlx -lXext -lX11 -lm
else
    $(error Système d'exploitation non pris en charge)
endif

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled libft source."

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "Compiled MinilibX source."

bonus: all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -s -C $(LIBFT)
	$(MAKE) clean -s -C $(MLX)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -s -C $(LIBFT)
	$(MAKE) clean -s -C $(MLX)

re: fclean all

.PHONY: all clean fclean re
