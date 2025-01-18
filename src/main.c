/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:16 by mbah              #+#    #+#             */
/*   Updated: 2025/01/18 00:52:17 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

// Fonction pour fermer la fenêtre
int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(ERROR);
	return (ERROR);
}

// Gestionnaire de pression de touches
int	key_press(int keycode, t_vars *vars)
{
	vars->keycode = keycode;
	printf("code : %i\n", keycode);
	if (keycode == KEY_ESC)
		close_window(vars);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_vars	data;
	t_line	red_line = {{100, 100}, {200, 200}, my_mlx_create_trgb(0, 255, 0, 0), 0};

	if (argc < 2)
		return (1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 520, 480, argv[1]);
	data.image.img = mlx_new_image(data.mlx, 520, 480);
	data.image.addr = mlx_get_data_addr(data.image.img,
			&data.image.bits_per_pixel, &data.image.line_length,
			&data.image.endian);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	draw_line_bresenham(&data.image, red_line);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.image.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
