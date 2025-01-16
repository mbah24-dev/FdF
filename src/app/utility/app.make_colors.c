/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.make_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:08 by mbah              #+#    #+#             */
/*   Updated: 2025/01/16 17:23:08 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_mlx_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	my_mlx_get_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	my_mlx_get_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int	my_mlx_get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	my_mlx_add_shade(double distance, int color)
{
	int	r;
	int	g;
	int	b;

	if (distance < 0)
		distance = 0;
	if (distance > 1)
		distance = 1;
	r = my_mlx_get_r(color);
	g = my_mlx_get_g(color);
	b = my_mlx_get_b(color);
	r = (int)(r * (1 - distance));
	g = (int)(g * (1 - distance));
	b = (int)(b * (1 - distance));
	return (my_mlx_create_trgb(0, r, g, b));
}
