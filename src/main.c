/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:32:38 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 19:43:35 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*get_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (!fdf)
		terminate(fdf, "MALLOC ERR: Memory allocation failed. ", 1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		free_only_fdf_exit(fdf, 0);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF-mbah");
	if (!fdf->mlx_win)
		free_only_fdf_exit(fdf, 1);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		free_only_fdf_exit(fdf, 2);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_height,
			&fdf->endian);
	fdf->map = NULL;
	fdf->camera = NULL;
	fdf->mouse = (t_mouse *) malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		free_only_fdf_exit(fdf, 3);
	return (fdf);
}

static t_camera	*get_camera(t_fdf *fdf)
{
	t_camera	*camera;
	int			shift_w;
	int			shift_h;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		terminate(fdf, "MALLOC ERR: Memory allocation failed.", 1);
	shift_w = (WIN_WIDTH / fdf->map->width) / 2;
	shift_h = (WIN_HEIGHT / fdf->map->height) / 2;
	camera->zoom = get_min_value(shift_w, shift_h);
	camera->x_alpha = -0.615472907;
	camera->y_beta = -0.523599;
	camera->z_gama = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

static t_map	*get_map(t_fdf *fdf)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		free_only_fdf_exit(fdf, 4);
	map->width = 0;
	map->height = 0;
	map->map_coord = NULL;
	map->z_min = 0;
	map->z_max = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc == 2)
	{
		fdf = get_fdf();
		fdf->map = get_map(fdf);
		check_the_map(fdf, fdf->map, argv[1]);
		fdf->camera = get_camera(fdf);
		fdf_hooks_controls(fdf);
		draw_map(fdf->map, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		terminate(fdf, "USAGE ERR: Please use << ./fdf <file_path>.", 0);
}
