/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:25:47 by mbah              #+#    #+#             */
/*   Updated: 2025/01/22 17:14:42 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "FdF_utils.h"
# include "get_next_line.h"
# include <stdio.h>
# include "FdF_key.h"
# include <time.h>

typedef enum e_flag
{
	TRUE = 1,
	FALSE = 0
}	t_flag;

typedef struct s_map
{
	char	**map_temp;
	int		width;
	int		height;
	t_point	*map_coord;
}			t_map;

typedef struct s_fdf
{
	t_map	map;
	t_data	image;
	void	*mlx;
	void	*mlx_win;
	int		zoom;
	int		shift_x;
	int		shift_y;
}	t_fdf;

/*===========  (main.c functions) ==========*/
int		close_win(t_fdf *fdf_data);
int		key_press(int keycode, t_fdf *fdf_data);
void	init_fdf(t_fdf *data, char **argv);

/*===========  (app.draw_line.c functions) ==========*/
void	draw_line_bresenham(t_data *img, t_point pt_src,
			t_point pt_dst, int color);

/*===========  (app.parse_map.c functions) ==========*/
char	***get_map_content(char **map, const char map_sep);
size_t	get_map_height(char **map);
size_t	get_map_width(char **map);
size_t	ft_countword(const char *str, char sep);
char	**get_the_map(char *path, char *argv_1);

/*===========  (app.init_point.c functions) ==========*/
char	*ft_strcat(char *s1, char *s2);


#endif
