/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_map_and_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:34:04 by mbah              #+#    #+#             */
/*   Updated: 2025/01/29 15:55:35 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_fd(t_fdf *fdf, int fd)
{
	if (close(fd) == -1)
		terminate(fdf, "CLOSE ERR: Bad file descriptor", 1);
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
}
