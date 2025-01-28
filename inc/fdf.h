/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:14:25 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 19:40:40 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Include header for key mappings depending on the OS */

# ifdef __APPLE__
#  include "macos_keys.h"
#  define MACOS			1
# elif __linux__
#  include "linux_keys.h"
#  define MACOS			0
# endif

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define WIN_WIDTH  900
# define WIN_HEIGHT 800

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}		t_point;

typedef struct s_camera
{
	int		zoom;
	double	x_alpha;
	double	y_beta;
	double	z_gama;
	float	z_height;
	int		iso;
	int		x_offset;
	int		y_offset;
}			t_camera;

typedef struct s_mouse
{
	int	x;
	int	y;
	int	previous_x;
	int	previous_y;
	int	button;
}		t_mouse;

typedef struct s_map
{
	int	height;
	int	width;
	int	z_max;
	int	z_min;
	int	***map_coord;
}		t_map;

typedef struct s_fdf
{
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			steep;
	char		*data_addr;
	int			bpp;
	int			line_height;
	int			endian;
}				t_fdf;

/* fdf_utils functions */

void	ft_put_pixel(t_fdf	*fdf, int x, int y, int color);
void	update_z_min_or_z_max(t_map *map, int nb);
void	terminate(t_fdf *fdf, char *error_msg, int type);
int		get_min_value(int first, int second);
int		get_initial_color(t_map *map, int z_axis);

/* app.projection.c functions*/
t_point	project_point(t_fdf *fdf, int x, int y);

/* app.parse_map.c functions */
void	check_the_map(t_fdf *fdf, t_map *map, const char *path);

/* app.mouse_event.c functions */
int		mouse_down_action(int button, int x, int y, void *vars);
int		mouse_up_action(int button, int x, int y, void *vars);
int		mouse_move_action(int x, int y, void *vars);

/* app.xiaolin_wu_line_utils.c functions */
float	get_value_abs(float value);
int		get_int_value(float value);
float	get_float_value(float value);
float	get_fraction_complement(float value);

/* app.xiaolin_wu_line.c functions */
void	draw_xiaolin_wu_line(t_point s, t_point e, t_fdf *fdf);

/* app.keyboard_event.c functions */
int		keyboard_press(int keycode, void *vars);

/* app.draw_map_and_menu.c functions */
void	draw_map(t_map *map, t_fdf *fdf);
void	close_fd(t_fdf *fdf, int fd);

/* app.hooks_controls.c functions */
int		close_win(void *vars);
void	fdf_hooks_controls(t_fdf *fdf);
double	reset_angles(double angle);
void	rotate_action(int key, t_fdf *fdf);
void	free_all(t_fdf *fdf);

int		convert_(char *color);

/* app.make_color_utils.c functions  */
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
int		make_color(int r, int g, int b);

#endif
