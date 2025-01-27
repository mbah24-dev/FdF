/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_map_and_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:34:04 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:30:44 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_fdf_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 0,
		0xFFFFF0, "LEFT CLICK: Move the map x/y");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 20,
		0xFFFFF0, "RIGHT CLICK: Rotate x/y axis");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 40,
		0xFFFFF0, "MIDDLE CLICK: Rotate z axis");
	if (fdf->camera->iso)
		mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 60,
			0x00FF00, "ENTER CLICK: Projection (Isometric)");
	else
		mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 60,
			0x00FF00, "ENTER CLICK: Projection (Parrallel)");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 80,
		0xFFFFF0, "R CLICK: Reset camera");
	mlx_string_put(fdf->mlx, fdf->mlx_win, WIN_WIDTH - 400, 100,
		0xFFFFF0, "+/-: Elevation");
}

static void	draw_lines_for_row(t_fdf *fdf, t_map *map, int *y)
{
	int	x;

	x = 0;
	if (fdf->camera->y_beta > 0)
		x = map->width - 1;
	while (x < map->width && x >= 0)
	{
		if (x != map->width - 1)
			draw_xiaolin_wu_line(project_point(fdf, x, *y),
				project_point(fdf, x + 1, *y), fdf);
		if (*y != map->height - 1)
			draw_xiaolin_wu_line(project_point(fdf, x, *y),
				project_point(fdf, x, *y + 1), fdf);
		x += -2 * (fdf->camera->y_beta > 0) + 1;
	}
	*y += -2 * (fdf->camera->x_alpha > 0) + 1;
}

void	draw_map(t_map *map, t_fdf *fdf)
{
	int	y;

	ft_bzero(fdf->data_addr, WIN_WIDTH * WIN_HEIGHT * (fdf->bpp / 8));
	y = 0;
	if (fdf->camera->x_alpha > 0)
		y = map->height - 1;
	while (y < map->height && y >= 0)
		draw_lines_for_row(fdf, map, &y);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	draw_fdf_menu(fdf);
}
