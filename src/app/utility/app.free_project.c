/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.free_project.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:04:15 by mbah              #+#    #+#             */
/*   Updated: 2025/01/29 16:04:56 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map_coord(t_fdf *fdf)
{
	int	i;
	int	j;

	j = -1;
	while (++j < fdf->map->height)
	{
		i = -1;
		while (++i < fdf->map->width)
		{
			free(fdf->map->map_coord[j][i]);
			fdf->map->map_coord[j][i] = NULL;
		}
		free(fdf->map->map_coord[j]);
		fdf->map->map_coord[j] = NULL;
	}
	free(fdf->map->map_coord);
	fdf->map->map_coord = NULL;
}

void	free_all(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->mlx_win)
			mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		if (fdf->camera)
			free(fdf->camera);
		if (fdf->mouse)
			free(fdf->mouse);
		if (fdf->map->map_coord)
			free_map_coord(fdf);
		if (fdf->map)
			free(fdf->map);
		if (fdf->mlx)
		{
			free(fdf->mlx);
		}
		free(fdf);
	}
}
