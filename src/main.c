/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:16 by mbah              #+#    #+#             */
/*   Updated: 2025/01/20 21:00:46 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	close_window(t_fdf *fdf_data)
{
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_win);
	exit(ERROR);
	return (ERROR);
}

int	key_press(int keycode, t_fdf *fdf_data)
{
	if (keycode == KEY_ESC)
		close_window(fdf_data);
	return (ERROR);
}

void	init_fdf(t_fdf *data, char **argv)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 520, 480, "Fil De Fer");
	data->image.img = mlx_new_image(data->mlx, 520, 480);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	data->map = get_the_map(ft_strcat("./public/maps/", argv[1]), argv[1]);
	data->map_height = get_map_height(data->map);
	data->map_width = get_map_width(data->map);
	data->map_points = init_point(data->map, data->map_width, data->map_height);
	data->zoom = 5;
	data->shift_x = 10;
	data->shift_y = 10;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc < 2)
		return (1);
	init_fdf(&data, argv);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.image.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
