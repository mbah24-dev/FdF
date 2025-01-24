/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.core.zoom_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:24:52 by mbah              #+#    #+#             */
/*   Updated: 2025/01/24 23:18:55 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	update_zoom_factor(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ZOOM_IN)
		fdf->zoom += 5;
	else if (keycode == KEY_ZOOM_OUT && fdf->zoom > 0)
		fdf->zoom -= 5;
	ft_printf("Zoom: %d\n", fdf->zoom);
}

void	do_translation(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->shift_y -= 3;
	if (keycode == KEY_DOWN)
		fdf->shift_y += 3;
	if (keycode == KEY_LEFT)
		fdf->shift_x -= 3;
	if (keycode == KEY_RIGHT)
		fdf->shift_x += 3;
	ft_printf("Shift X: %d, Shift Y: %d\n", fdf->shift_x, fdf->shift_y);
}

void	clear_image(t_data *image)
{
	ft_memset(image->addr, 0, DIMW_X * DIMW_Y * (image->bits_per_pixel / 8));
}
