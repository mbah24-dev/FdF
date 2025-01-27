/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:59:53 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:34:23 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	rotate_x_axis(int *y, int *z, double x_alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(x_alpha) + (*z) * sin(x_alpha);
	*z = previous_y * (-sin(x_alpha)) + (*z) * cos(x_alpha);
}

static	void	rotate_y_axis(int *x, int *z, double y_beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(y_beta) + (*z) * sin(y_beta);
	*z = previous_x * (-sin(y_beta)) + (*z) * cos(y_beta);
}

static	void	rotate_z_axis(int *x, int *y, double z_gama)
{
	t_point	previous;

	previous.x = *x;
	previous.y = *y;
	*x = previous.x * cos(z_gama) - previous.y * sin(z_gama);
	*y = previous.x * sin(z_gama) + previous.y * cos(z_gama);
}

static void	zoom_and_shift(t_fdf *fdf, t_point *pt, int x, int y)
{
	pt->x = x * fdf->camera->zoom;
	pt->y = y * fdf->camera->zoom;
	pt->z *= fdf->camera->zoom / fdf->camera->z_height;
	pt->x = pt->x - (fdf->map->width * fdf->camera->zoom) / 2;
	pt->y = pt->y - (fdf->map->height * fdf->camera->zoom) / 2;
}

/**
 * @brief Projette un point 3D sur l'écran
 en appliquant les transformations nécessaires.
 * 
 * Cette fonction prend un point 3D défini
 * par ses coordonnées (x, y, z) dans la carte,
 * et applique plusieurs transformations : 
 * zoom, centrage, rotation, et décalage.
 * Elle retourne le point projeté prêt à être affiché 
 *sur une fenêtre 2D.
 * 
 * @param x Coordonnée X du point dans la carte.
 * @param y Coordonnée Y du point dans la carte.
 * @param fdf Structure principale contenant les données de la carte,
 * de la caméra et autres paramètres.
 * @return t_point Le point transformé, prêt pour l'affichage à l'écran.
 * 
 * @note Cette fonction fait appel aux fonctions auxiliaires
 * `rotate_x_axis`, `rotate_y_axis` et `rotate_z_axis`
 * pour gérer les rotations 3D.
 */
t_point	project_point(t_fdf *fdf, int x, int y)
{
	t_point	point;
	int		y_shift;

	point.z = fdf->map->map_coord[y][x][0];
	if (fdf->map->map_coord[y][x][1] >= 0)
		point.color = fdf->map->map_coord[y][x][1];
	else
		point.color = get_initial_color(fdf->map, point.z);
	zoom_and_shift(fdf, &point, x, y);
	rotate_x_axis(&point.y, &point.z, fdf->camera->x_alpha);
	rotate_y_axis(&point.x, &point.z, fdf->camera->y_beta);
	rotate_z_axis(&point.x, &point.y, fdf->camera->z_gama);
	point.x = point.x + WIN_WIDTH / 2 + fdf->camera->x_offset;
	y_shift = (WIN_HEIGHT + fdf->map->height / 2 * fdf->camera->zoom) / 2;
	point.y = point.y + y_shift + fdf->camera->y_offset;
	point.reverse = 0;
	return (point);
}
