/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:16 by mbah              #+#    #+#             */
/*   Updated: 2025/01/22 17:16:12 by mbah             ###   ########.fr       */
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
	return (FALSE);
}
#include <stdio.h>
void	init_fdf(t_fdf *data, char **argv)
{
	char	***values = NULL;
	int		i;
	//int		j;

	i = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 520, 480, "Fil De Fer");
	data->image.img = mlx_new_image(data->mlx, 520, 480);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	data->map.map_temp = get_the_map(ft_strcat("./public/maps/", argv[1]), argv[1]);
	//remove_nl(data->map.map_temp);
	while (data->map.map_temp[i])
	{
		ft_printf("%s\n", data->map.map_temp[i]);
		i++;
	}
	ft_printf("%s\n", data->map.map_temp[i]);
	i = 0;
	//remove_nl(data->map.map_temp);
	//values = get_map_content(data->map.map_temp, ' ');
	ft_printf("%s", data->map.map_temp[0]);
	values[0] = split(data->map.map_temp[0], ' ');
	ft_printf("%s", values[0]);
	/*while (values[i])
	{
		j = 0;
		while (values[i][j])
		{
			printf("[x: %i, y: %i, z:  %s], ", j, i, values[i][j]);
			j++;
		}
		i++;
	}*/
}

int	main(int argc, char **argv)
{
	t_fdf	data;
	t_point	centre = {100, 150, 12, 0123};
	if (argc < 2)
		return (1);
	init_fdf(&data, argv);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	my_mlx_draw_circle(&data.image, centre, 20, 0xFF0000 >> 8);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.image.img, 0, 0);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
