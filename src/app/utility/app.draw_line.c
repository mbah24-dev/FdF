/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:02 by mbah              #+#    #+#             */
/*   Updated: 2025/01/18 01:01:07 by mbah             ###   ########.fr       */
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

void	draw_line_bresenham(t_data *img, t_line line)
{
	t_bresenham	vars;
	int			e2;

	init_bresenham_vars(&vars, line.pt_src, line.pt_dst);
	while (1)
	{
		my_mlx_pixel_put(img, line.pt_src.x, line.pt_src.y, line.color);
		if (line.pt_src.x == line.pt_dst.x && line.pt_src.y == line.pt_dst.y)
			break ;
		e2 = vars.err;
		if (e2 > -vars.dx)
		{
			vars.err -= vars.dy;
			line.pt_src.x += vars.sx;
		}
		if (e2 < vars.dy)
		{
			vars.err += vars.dx;
			line.pt_src.y += vars.sy;
		}
	}
}
