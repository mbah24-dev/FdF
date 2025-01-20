/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.init_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:05:22 by mbah              #+#    #+#             */
/*   Updated: 2025/01/20 20:16:01 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	char	*res;
	size_t	len;

	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	len = ft_strlen(s1);
	while (s2[++i])
		res[i + len] = s2[i];
	res[i + len] = '\0';
	return (res);
}

int	get_z(char *z_and_color)
{
	char	**temp;

	temp = ft_split(z_and_color, ',');
	return (ft_atoi(temp[0]));
}

int	get_color(char *z_and_color)
{
	char	**temp;

	temp = ft_split(z_and_color, ',');
	return (ft_atoi(temp[1]));
}

t_point	create_point(int x, int y, char *z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z_and_color = z;
	return (point);
}

t_point	*init_point(char **map, int w, int h)
{
	t_point	*map_points;
	int		i;
	int		j;
	int		k;
	char	***values;

	map_points = (t_point *) malloc(sizeof(t_point) * ((w * h) + 1));
	if (!map_points)
		return (NULL);
	i = 0;
	j = 0;
	values = get_map_content(map, ' ');
	while (i < w * h)
	{
		k = 0;
		while (k < w)
		{
			map_points[i] = create_point(k, j, values[j][k]);
			k++;
			i++;
		}
		j++;
	}
	map_points[i] = create_point(-1, -1, "-");
	return (map_points);
}
