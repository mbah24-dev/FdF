/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:16 by mbah              #+#    #+#             */
/*   Updated: 2025/01/17 18:34:41 by mbah             ###   ########.fr       */
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

// Remplir l'image avec une couleur de fond (ici noir)
void	clear_image(t_data *image, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(image, y, x, my_mlx_create_trgb(0, 0, 0, 0));
			x++;
		}
		y++;
	}
}

int	update_circle(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	clear_image(&vars->image, 520, 480);
	
	if (vars->keycode == KEY_UP)
		vars->circle_pos.y -= 3;
	if (vars->keycode == KEY_DOWN)
		vars->circle_pos.y += 3;
	if (vars->keycode == KEY_RIGHT)
		vars->circle_pos.x += 3;
	if (vars->keycode == KEY_LEFT)
		vars->circle_pos.x -= 3;
	vars->keycode = 0;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->moquette.img, 0, 0);
	my_mlx_draw_circle(&vars->image, vars->circle_pos, 50,
		my_mlx_create_trgb(0, 0, 0, 255));
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image.img, 0, 0);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_vars		data;
	t_point		pt;

	if (argc < 2)
		return (1);
	pt.x = 100;
	pt.y = 100;
	data.circle_pos = pt;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 520, 480, argv[1]);
	data.image.img = mlx_new_image(data.mlx, 520, 480);
	data.image.addr = mlx_get_data_addr(data.image.img,
			&data.image.bits_per_pixel, &data.image.line_length,
			&data.image.endian);
	data.moquette.path = "./public/data/moq.xpm";
	data.moquette.img = mlx_xpm_file_to_image(data.mlx, data.moquette.path,
			&data.moquette.width, &data.moquette.height);
	if (!data.moquette.img)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.moquette.img, 0, 0);
	mlx_loop_hook(data.mlx, update_circle, &data);
	my_mlx_draw_circle(&data.image, data.circle_pos, 50,
		my_mlx_create_trgb(0, 0, 0, 255));
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.image.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
