/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:33:39 by mbah              #+#    #+#             */
/*   Updated: 2025/01/16 17:52:12 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_utils.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	my_mlx_draw_square(t_data *img, t_point O, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, O.x + i, O.y + j, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_draw_circle(t_data *img, t_point centre, int r, int color)
{
	int	x;
	int	y;

	x = -r;
	while (x <= r)
	{
		y = -r;
		while (y <= r)
		{
			if ((x * x) + (y * y) <= (r * r))
				my_mlx_pixel_put(img, centre.x + x, centre.y + y, color);
			y++;
		}
		x++;
	}
}
