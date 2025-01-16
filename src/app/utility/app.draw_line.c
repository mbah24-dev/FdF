/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:02 by mbah              #+#    #+#             */
/*   Updated: 2025/01/16 17:52:34 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF_utils.h"

static void	my_mlx_draw_oblic1_line(t_data *img, t_point A, t_point B,
	int color)
{
	int	i;
	int	j;

	i = A.x;
	j = 0;
	while (i <= B.x)
	{
		my_mlx_pixel_put(img, A.x + j, A.y + j, color);
		j++;
		i++;
	}
}

static void	my_mlx_draw_oblic2_line(t_data *img, t_point A, t_point B,
	int color)
{
	int	i;
	int	j;

	i = B.x;
	j = 0;
	while (i >= A.x)
	{
		my_mlx_pixel_put(img, A.x + j, A.y - j, color);
		j++;
		i--;
	}
}

static void	my_mlx_draw_samex_line(t_data *img, t_point A, t_point B, int color)
{
	int	inc;

	if (A.y < B.y)
		inc = 1;
	else
		inc = -1;
	while (1)
	{
		my_mlx_pixel_put(img, A.x, A.y, color);
		if (A.y == B.y)
			break ;
		if (inc == 1)
			A.y += inc;
		else
			A.y += inc;
	}
}

static void	my_mlx_draw_samey_line(t_data *img, t_point A, t_point B, int color)
{
	int	inc;

	if (A.x < B.x)
		inc = 1;
	else
		inc = -1;
	while (1)
	{
		my_mlx_pixel_put(img, A.x, A.y, color);
		if (A.x == B.x)
			break ;
		if (inc == 1)
			A.x += inc;
		else
			A.x += inc;
	}
}

void	my_mlx_draw_line(t_data *img, t_point A, t_point B, int color)
{
	if (A.y < B.y && A.x < B.x)
		my_mlx_draw_oblic1_line(img, A, B, color);
	else if (A.y > B.y && A.x < B.x)
		my_mlx_draw_oblic2_line(img, A, B, color);
	else if (A.x == B.x)
		my_mlx_draw_samex_line(img, A, B, color);
	else if (A.y == B.y)
		my_mlx_draw_samey_line(img, A, B, color);
}
