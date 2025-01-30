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

void	free_only_fdf_exit(t_fdf *fdf, int indx)
{
	if (indx > 3)
		free(fdf->mouse);
	if (indx > 2)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (indx > 1)
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	if (indx > 0)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
	ft_putstr_fd("INIT ERR: ", 1);
	exit(-1);
}

void	free_split(t_fdf *fdf, char **str, int fd, char *line)
{
	int	i;

	i = -1;
	if (!str && (fd == -1) && !line)
		terminate(fdf, "SPLIT VALUE ERR:", 1);
	if (str)
	{
		while (str[++i])
			if (str[i])
				free(str[i]);
		free(str);
	}
	free(line);
	while (1)
	{
		line = get_next_line(fdf->fd);
		if (!line)
			break ;
		free(line);
	}
	close_fd(fdf, fdf->fd);
	terminate(fdf, "ERROR: ", 1);
}

static void	free_map_coord(t_fdf *fdf)
{
	int	i;
	int	j;

	j = -1;
	while (++j < fdf->map->height)
	{
		i = -1;
		if (fdf->map->map_coord[j])
		{
			while (++i < fdf->map->width)
			{
				if (fdf->map->map_coord[j][i])
					free(fdf->map->map_coord[j][i]);
			}
			free(fdf->map->map_coord[j]);
		}
	}
	free(fdf->map->map_coord);
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
			if (!MACOS)
				mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		free(fdf);
	}
}
