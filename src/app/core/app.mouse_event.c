/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:10:38 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 17:46:09 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_action(int button, t_fdf *fdf)
{
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	if (button == MOUSE_WHEEL_DOWN)
		fdf->camera->zoom -= 1;
	else if (button == MOUSE_WHEEL_UP)
		fdf->camera->zoom += 1;
	draw_map(fdf->map, fdf);
}

int	mouse_down_action(int button, int x, int y, void *vars)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) vars;
	if (MACOS)
	{
		if (button == MOUSE_CLICK_RIGHT || button == MOUSE_CLICK_LEFT
			|| button == MOUSE_CLICK_MIDDLE)
		{
			fdf->mouse->button = button;
			fdf->mouse->previous_x = x;
			fdf->mouse->previous_y = y;
		}
	}
	if (button == MOUSE_WHEEL_DOWN || button == MOUSE_WHEEL_UP)
		zoom_action(button, fdf);
	return (0);
}

int	mouse_up_action(int button, int x, int y, void *vars)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) vars;
	(void)x;
	(void)y;
	if (button == MOUSE_CLICK_MIDDLE || button == MOUSE_CLICK_RIGHT
		|| button == MOUSE_CLICK_LEFT)
		fdf->mouse->button = 0;
	return (0);
}

static void	move_z_axis_action(int x, int y, t_fdf *fdf)
{
	if (x >= (WIN_WIDTH / 2) + fdf->camera->x_offset)
		fdf->camera->z_gama += (y - fdf->mouse->previous_y) * 0.002;
	else
		fdf->camera->z_gama -= (y - fdf->mouse->previous_y) * 0.002;
	fdf->mouse->previous_x = x;
	fdf->mouse->previous_y = y;
	draw_map(fdf->map, fdf);
}

int	mouse_move_action(int x, int y, void *vars)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)vars;
	if (fdf->mouse->button == MOUSE_CLICK_LEFT)
	{
		fdf->camera->x_offset += (x - fdf->mouse->previous_x);
		fdf->camera->y_offset += (y - fdf->mouse->previous_y);
		fdf->mouse->previous_x = x;
		fdf->mouse->previous_y = y;
		draw_map(fdf->map, fdf);
	}
	if (fdf->mouse->button == MOUSE_CLICK_MIDDLE)
		move_z_axis_action(x, y, fdf);
	else if (fdf->mouse->button == MOUSE_CLICK_RIGHT)
	{
		fdf->camera->x_alpha += (y - fdf->mouse->previous_y) * 0.002;
		fdf->camera->y_beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->x_alpha = reset_angles(fdf->camera->x_alpha);
		fdf->camera->y_beta = reset_angles(fdf->camera->y_beta);
		fdf->mouse->previous_x = x;
		fdf->mouse->previous_y = y;
		draw_map(fdf->map, fdf);
	}
	draw_map(fdf->map, fdf);
	return (0);
}
