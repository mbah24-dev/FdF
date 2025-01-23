/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:02 by mbah              #+#    #+#             */
/*   Updated: 2025/01/23 17:04:22 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	init_bresenham_vars(t_bresenham *vars, t_point p0, t_point p1)
{
	vars->dx = abs(p1.x - p0.x);
	vars->dy = abs(p1.y - p0.y);
	if (p0.x < p1.x)
		vars->sx = 1;
	else
		vars->sx = -1;
	if (p0.y < p1.y)
		vars->sy = 1;
	else
		vars->sy = -1;
	if (vars->dx > vars->dy)
		vars->err = vars->dx / 2;
	else
		vars->err = -vars->dy / 2;
}

void	draw_line_bresenham(t_data *img, t_point pt_src,
	t_point pt_dst, int color)
{
	t_bresenham	vars;
	int			e2;

	if (pt_src.z == 2147483648 || pt_dst.z == 2147483648)
		return ;
	init_bresenham_vars(&vars, pt_src, pt_dst);
	while (1)
	{
		my_mlx_pixel_put(img, pt_src.x, pt_src.y, color);
		if (pt_src.x == pt_dst.x && pt_src.y == pt_dst.y)
			break ;
		e2 = vars.err;
		if (e2 > -vars.dx)
		{
			vars.err -= vars.dy;
			pt_src.x += vars.sx;
		}
		if (e2 < vars.dy)
		{
			vars.err += vars.dx;
			pt_src.y += vars.sy;
		}
	}
}
