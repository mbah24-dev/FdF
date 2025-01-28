/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hooks_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:13:41 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 17:25:36 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_action(int key, t_fdf *fdf)
{
	if (key == X_KEY)
		fdf->camera->x_alpha += 0.05;
	else if (key == A_KEY)
		fdf->camera->x_alpha -= 0.05;
	else if (key == Y_KEY)
		fdf->camera->y_beta += 0.05;
	else if (key == B_KEY)
		fdf->camera->y_beta -= 0.05;
	else if (key == Z_KEY)
		fdf->camera->z_gama += 0.05;
	else if (key == C_KEY)
		fdf->camera->z_gama -= 0.05;
	fdf->camera->x_alpha = reset_angles(fdf->camera->x_alpha);
	fdf->camera->y_beta = reset_angles(fdf->camera->y_beta);
	fdf->camera->z_gama = reset_angles(fdf->camera->z_gama);
	draw_map(fdf->map, fdf);
}

int	close_win(void *vars)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	fdf = (t_fdf *)vars;
	mlx_destroy_image(fdf->mlx, fdf->img);
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

void fdf_hooks_controls(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, EVENT_KEY_PRESS, MASK_KEY_PRESS, keyboard_press, fdf);
	mlx_hook(fdf->mlx_win, EVENT_MOUSE_DOWN, MASK_BUTTON_PRESS, mouse_down_action, fdf);
	if (MACOS)
	{
		mlx_hook(fdf->mlx_win, EVENT_MOUSE_UP, MASK_BUTTON_RELEASE, mouse_up_action, fdf);
		mlx_hook(fdf->mlx_win, EVENT_MOUSE_MOVE, MASK_POINTER_MOTION, mouse_move_action, fdf);
	}
	mlx_hook(fdf->mlx_win, EVENT_DESTROY, MASK_STRUCTURE_NOTIFY, close_win, fdf);
}

double	reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
