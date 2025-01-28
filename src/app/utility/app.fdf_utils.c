/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.fdf_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:04 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 19:30:53 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf	*fdf, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		dst = fdf->data_addr + (y * fdf->line_height + x * (fdf->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int	get_min_value(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

void	update_z_min_or_z_max(t_map *map, int nb)
{
	if (nb > map->z_max)
		map->z_max = nb;
	if (nb < map->z_min)
		map->z_min = nb;
}

int	get_initial_color(t_map *map, int z_axis)
{
	double			factor;
	unsigned int	max_val;

	max_val = map->z_max - map->z_min;
	if (max_val == 0)
		return (0xFFA500);
	factor = ((double)(z_axis - map->z_min) / max_val);
	if (factor < 0.2)
		return (0x006400);
	else if (factor < 0.4)
		return (0x32CD32);
	else if (factor < 0.6)
		return (0xFFD700);
	else if (factor < 0.8)
		return (0xFF8C00);
	else
		return (0xFFA500);
}

void	terminate(t_fdf *fdf, char *error_msg, int type)
{
	if (!type)
		ft_putendl_fd(error_msg, STDERR_FILENO);
	else
		perror(error_msg);
	free_all(fdf);
	exit(-1);
}
