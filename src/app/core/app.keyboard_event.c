/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.keyboard_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:54:03 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 16:26:45 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_camera(t_fdf *fdf)
{
	int	shift_w;
	int	shift_h;

	fdf->camera->x_offset = 0;
	fdf->camera->y_offset = 0;
	if (fdf->camera->iso)
	{
		fdf->camera->x_alpha = -0.615472907;
		fdf->camera->y_beta = -0.523599;
		fdf->camera->z_gama = 0.615472907;
	}
	else
	{
		fdf->camera->x_alpha = -0.523599;
		fdf->camera->y_beta = -0.261799;
		fdf->camera->z_gama = 0;
	}
	fdf->camera->z_height = 1;
	shift_w = (WIN_WIDTH / fdf->map->width) / 2;
	shift_h = (WIN_HEIGHT / fdf->map->height) / 2;
	fdf->camera->zoom = get_min_value(shift_w, shift_h);
}

static void	toggle_projection(t_fdf *fdf)
{
	if (fdf->camera->iso)
	{
		fdf->camera->x_alpha = -0.523599;
		fdf->camera->y_beta = -0.261799;
		fdf->camera->z_gama = 0;
	}
	else
	{
		fdf->camera->x_alpha = -0.615472907;
		fdf->camera->y_beta = -0.523599;
		fdf->camera->z_gama = 0.615472907;
	}
	fdf->camera->iso = !fdf->camera->iso;
}

static void	mod_height_view(int keycode, t_fdf *fdf)
{
	if (keycode == MINUS)
		fdf->camera->z_height += 0.1;
	else if (keycode == PLUS)
		fdf->camera->z_height -= 0.1;
	if (fdf->camera->z_height < 0.1)
		fdf->camera->z_height = 0.1;
	else if (fdf->camera->z_height > 10)
		fdf->camera->z_height = 10;
}

static void	translate_map(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_UP)
		fdf->camera->y_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	else if (keycode == ARROW_DOWN)
		fdf->camera->y_offset += 10;
	else if (keycode == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
}

int	keyboard_press(int keycode, void *vars)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)vars;
	if (keycode == ARROW_DOWN || keycode == ARROW_LEFT
		|| keycode == ARROW_UP || keycode == ARROW_RIGHT)
		translate_map(keycode, fdf);
	else if (keycode == MINUS || keycode == PLUS)
		mod_height_view(keycode, fdf);
	else if (keycode == ENTER)
		toggle_projection(fdf);
	else if (keycode == RESET_KEY)
		reset_camera(fdf);
	else if (keycode == ESCAPE)
		close_win(fdf);
	else if (keycode == X_KEY || keycode == Y_KEY
			|| keycode == Z_KEY)
		rotate_action(keycode, fdf);
	draw_map(fdf->map, fdf);
	return (0);
}
