/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hooks_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:13:41 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:01:11 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(void *vars)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	fdf = (t_fdf *)vars;
	mlx_destroy_image(fdf->mlx, fdf->mlx_win);
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	free(fdf->camera);
	free(fdf->mouse);
	j = -1;
	while (++j < fdf->map->height)
	{
		i = -1;
		while (++i < fdf->map->width)
			free(fdf->map->map_coord[j][i]);
		free(fdf->map->map_coord[j]);
	}
	free(fdf->map->map_coord);
	free(fdf->map);
	free(fdf->mlx);
	free(fdf);
	exit(0);
}

void	fdf_hooks_controls(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 0, keyboard_press, fdf);
	mlx_hook(fdf->mlx_win, 4, 0, mouse_down_action, fdf);
	mlx_hook(fdf->mlx_win, 5, 0, mouse_up_action, fdf);
	mlx_hook(fdf->mlx_win, 6, 0, mouse_move_action, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, close_win, fdf);
}

double	reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
