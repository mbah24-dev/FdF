/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.xiaolin_wu_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:03:20 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:45:37 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	linear_interp(int fst, int snd, double factor)
{
	return ((int)((double)fst + (snd - fst) * factor));
}

static int	get_color(t_point s, t_point e, int x, float factor)
{
	int		r;
	int		g;
	int		b;
	float	perc;

	perc = get_value_abs(x - s.x) / get_value_abs(e.x - s.x);
	if (s.reverse)
	{
		r = linear_interp(get_r(e.color), get_r(s.color), perc);
		g = linear_interp(get_g(e.color), get_g(s.color), perc);
		b = linear_interp(get_b(e.color), get_b(e.color), perc);
	}
	else
	{
		r = linear_interp(get_r(s.color), get_r(e.color), perc);
		g = linear_interp(get_g(s.color), get_g(e.color), perc);
		b = linear_interp(get_b(s.color), get_b(e.color), perc);
	}
	return (make_color(r * factor, g * factor, b * factor));
}

static void	swap_a_b(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	draw_line(t_fdf *fdf, t_point s, t_point e, float gradient)
{
	float	y_temp;
	int		x;

	y_temp = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (fdf->steep)
		{
			ft_put_pixel(fdf, get_int_value(y_temp), x,
				get_color(s, e, x, get_fraction_complement(y_temp)));
			ft_put_pixel(fdf, get_int_value(y_temp) + 1, x,
				get_color(s, e, x, get_float_value(y_temp)));
		}
		else
		{
			ft_put_pixel(fdf, x, get_int_value(y_temp),
				get_color(s, e, x, get_fraction_complement(y_temp)));
			ft_put_pixel(fdf, x, get_int_value(y_temp) + 1,
				get_color(s, e, x, get_float_value(y_temp)));
		}
		y_temp += gradient;
		x++;
	}
}

void	draw_xiaolin_wu_line(t_point s, t_point e, t_fdf *fdf)
{
	float	dy;
	float	dx;
	float	gradient;

	fdf->steep = get_value_abs(e.y - s.y) > get_value_abs(e.x - s.x);
	if (fdf->steep)
	{
		swap_a_b(&s.x, &s.y);
		swap_a_b(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		swap_a_b(&s.x, &e.x);
		swap_a_b(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	draw_line(fdf, s, e, gradient);
}
