/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:32:38 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:19:07 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*get_fdf(void)
{
	t_fdf	*fdf;
	char	*proj_title;

	proj_title = ft_strdup("mbah-42 FdF - Project");
	fdf = (t_fdf *) malloc(sizeof(t_fdf));
	if (!fdf)
		terminate("MALLOC ERR: Memory allocation failed. ", 1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate("MLX ERR:  Error connecting to graphics server", 1);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, proj_title);
	if (!fdf->mlx_win)
		terminate("MLX ERR:  Error initializing window", 1);
	free(proj_title);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		terminate("MLX ERR:  Error initializing image", 1);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_height,
			&fdf->endian);
	fdf->map = NULL;
	fdf->camera = NULL;
	fdf->mouse = (t_mouse *) malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		terminate("MOUSE ERR:  Error initializing mouse", 1);
	return (fdf);
}

static t_camera	*get_camera(t_fdf *fdf)
{
	t_camera	*camera;
	int			shift_w;
	int			shift_h;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		terminate("MALLOC ERR: Memory allocation failed.", 1);
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

static t_map	*get_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		terminate("MALLOC ERR: Memory allocation failed.", 1);
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

	if (argc == 2)
	{
		fdf = get_fdf();
		fdf->map = get_map();
		check_the_map(fdf->map, argv[1]);
		fdf->camera = get_camera(fdf);
		fdf_hooks_controls(fdf);
		draw_map(fdf->map, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		terminate("USAGE ERR: Please use << ./fdf <file_path>.", 0);
}
