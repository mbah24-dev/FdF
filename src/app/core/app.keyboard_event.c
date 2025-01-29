/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.keyboard_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:54:03 by mbah              #+#    #+#             */
/*   Updated: 2025/01/29 15:55:38 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard_press(int keycode, void *vars)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)vars;
	if (keycode == ESCAPE)
		close_win(fdf);
	draw_map(fdf->map, fdf);
	return (0);
}
