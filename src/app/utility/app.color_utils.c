/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:37:06 by mbah              #+#    #+#             */
/*   Updated: 2025/01/27 19:39:08 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_r(int color)
{
	return (color >> 16 & 0xFF);
}

int	get_g(int color)
{
	return (color >> 8 & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	make_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
