/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.convert_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 02:42:47 by mbah              #+#    #+#             */
/*   Updated: 2025/01/26 16:35:39 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_index(char *base, char value)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static int	get_power(int n, int pow)
{
	int	res;

	res = n;
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		res = res * n;
		pow--;
	}
	return (res);
}

int	convert_(char *color)
{
	char	*base;
	int		res;
	int		i;
	int		i_temp;
	size_t	color_size;

	base = "0123456789ABCDEF";
	i = 2;
	color_size = ft_strlen(color) - 3;
	res = 0;
	while (color[i])
	{
		i_temp = get_index(base, color[i]);
		if (i_temp == -1)
			return (0xFFFFFF);
		res += i_temp * get_power(16, color_size);
		color_size--;
		i++;
	}
	if (res <= 0)
		return (0xFFFFFF);
	return (res);
}
