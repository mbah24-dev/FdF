/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:24:13 by mbah              #+#    #+#             */
/*   Updated: 2025/01/23 15:45:08 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
	long	z;
	int		color;
	int		is_last;
}		t_point;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_bresenham;

int		my_mlx_create_trgb(int t, int r, int g, int b);
int		my_mlx_get_r(int trgb);
int		my_mlx_get_g(int trgb);
int		my_mlx_get_b(int trgb);
int		my_mlx_add_shade(double distance, int color);
void	remove_nl(char *str);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	my_mlx_draw_square(t_data *img, t_point O, int size, int color);
void	my_mlx_draw_circle(t_data *img, t_point centre, int r, int color);

#endif