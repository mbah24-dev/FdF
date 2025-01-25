/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:16 by mbah              #+#    #+#             */
/*   Updated: 2025/01/25 03:08:51 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	close_window(t_fdf *fdf_data)
{
	mlx_destroy_window(fdf_data->mlx, fdf_data->mlx_win);
	exit(FALSE);
	return (FALSE);
}

int	key_press(int keycode, t_fdf *fdf_data)
{
	if (keycode == KEY_ESC)
		close_window(fdf_data);
	ft_printf("%i\n", keycode);
	update_zoom_factor(keycode, fdf_data);
	do_translation(keycode, fdf_data);
	renderer(fdf_data);
	return (FALSE);
}

void	free_all(t_fdf fdf)
{
	int	i;

	i = -1;
	while (fdf.map.map_temp[++i])
		free(fdf.map.map_temp[i]);
	free(fdf.map.map_temp);
	free(fdf.map.map_coord);
}

void	init_fdf(t_fdf *data, char **argv)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, DIMW_X, DIMW_Y, "Fil De Fer");
	data->image.img = mlx_new_image(data->mlx, DIMW_X, DIMW_Y);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	data->map.map_temp = get_the_map(ft_strcat("./public/maps/",
				argv[1]), argv[1]);
	if (data->map.map_temp[0] == NULL)
	{
		ft_printf("Error: Invalid map (x)");
		exit(TRUE);
	}
	data->map.width = get_map_width(data->map.map_temp);
	data->map.height = get_map_height(data->map.map_temp);
	data->map.map_coord = init_map_points(data->map);
	data->zoom = 20;
	data->shift_x = 0;
	data->shift_y = 50;
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc < 2)
		return (1);
	init_fdf(&data, argv);
	ft_printf("w: %i\n", data.map.width);
	ft_printf("h: %i\n", data.map.height);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	renderer(&data);
	//mlx_put_image_to_window(data.mlx, data.mlx_win, data.image.img, 0, 0);
	//mlx_loop_hook(data.mlx, renderer, &data);
	mlx_loop(data.mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
