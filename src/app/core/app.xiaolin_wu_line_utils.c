/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.xiaolin_wu_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:46:04 by mbah              #+#    #+#             */
/*   Updated: 2025/01/26 16:31:57 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_value_abs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	get_int_value(float value)
{
	return ((int)value);
}

float	get_float_value(float value)
{
	if (value > 0.f)
		return (value - get_int_value(value));
	return (value - (get_int_value(value) + 1.f));
}

float	get_fraction_complement(float value)
{
	return (1.f - get_float_value(value));
}
