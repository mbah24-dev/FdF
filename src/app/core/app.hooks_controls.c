/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hooks_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:13:41 by mbah              #+#    #+#             */
/*   Updated: 2025/01/29 15:55:36 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (!MACOS)
		mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(0);
}

void	fdf_hooks_controls(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, EVENT_KEY_PRESS,
		1L << MASK_KEY_PRESS, keyboard_press, fdf);
	mlx_hook(fdf->mlx_win, EVENT_DESTROY,
		1L << MASK_STRUCTURE_NOTIFY, close_win, fdf);
}
