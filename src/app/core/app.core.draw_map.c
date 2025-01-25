/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.core.draw_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:05:05 by mbah              #+#    #+#             */
/*   Updated: 2025/01/25 03:09:28 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	renderer(t_fdf *fdf)
{
	clear_image(&fdf->image);
	zoom_map(fdf);
	do_shift(fdf);
	do_isometric_view(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->image.img, 0, 0);
	return (0);
}

void	do_shift(t_fdf *fdf)
{
	int	i;
	int	nb_pts;
	int	shift_x;

	i = 0;
	nb_pts = get_nb_points(fdf->map.map_coord);
	shift_x = (DIMW_X / 2) - (fdf->map.width * fdf->zoom / 2);
	while (i < nb_pts)
	{
		fdf->map.map_coord[i].x += shift_x + fdf->shift_x;
		fdf->map.map_coord[i].y += fdf->shift_y;
		i++;
	}
}

void	do_isometric_view(t_fdf *fdf)
{
	int	i;
	int	nb_pts;
	int	px;
	int	py;
	int	tmp;

	i = 0;
	nb_pts = get_nb_points(fdf->map.map_coord);
	while (i < nb_pts)
	{
		tmp = fdf->map.map_coord[i].x;
		py = fdf->map.map_coord[i].z;
		px = (tmp - fdf->map.map_coord[i].y) * cos(0.523599);
 		py = (tmp + fdf->map.map_coord[i].y) * sin(0.523599) - py;
		fdf->map.map_coord[i].x = px;
		fdf->map.map_coord[i].y = py;
		i++;
	}
}

void	zoom_map(t_fdf *fdf)
{
	int	i;
	int	nb_pts;

	i = 0;
	nb_pts = get_nb_points(fdf->map.map_coord);
	while (i < nb_pts)
	{
		fdf->map.map_coord[i].x *= fdf->zoom;
		fdf->map.map_coord[i].y *= fdf->zoom;
		if (fdf->map.map_coord[i].z != 2147483648)
			fdf->map.map_coord[i].z *= fdf->zoom;
		i++;
	}
}

void	draw_map(t_fdf *fdf)
{
	int		i;
	int		width;
	int		nb_pts;
	t_point	pt1;
	t_point	pt2;

	i = 0;
	width = fdf->map.width;
	nb_pts = get_nb_points(fdf->map.map_coord);
	while (i < nb_pts - 1 && fdf->map.map_coord[i + 1].x >= 0)
	{
		if ((i + 1) % width != 0)
		{
			pt1 = fdf->map.map_coord[i];
			pt2 = fdf->map.map_coord[i + 1];
			draw_line_bresenham(&fdf->image, pt1, pt2, pt1.color);
		}
		if (i < (nb_pts - width))
		{
			pt1 = fdf->map.map_coord[i];
			pt2 = fdf->map.map_coord[i + width];
			draw_line_bresenham(&fdf->image, pt1, pt2, pt2.color);
		}
		i++;
	}
}
