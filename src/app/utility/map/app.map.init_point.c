/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.map.init_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:05:22 by mbah              #+#    #+#             */
/*   Updated: 2025/01/24 23:03:31 by mbah             ###   ########.fr       */
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

t_point	create_point(int x, int y, char *z_color, int is_last)
{
	t_point	pt;
	int		color;
	char	**temp;

	temp = ft_split(z_color, ',');
	pt.x = x;
	pt.y = y;
	if (ft_strncmp(temp[0], "2147483648", ft_strlen("2147483648")) != 0)
		pt.z = ft_atoi(temp[0]);
	else
		pt.z = 2147483648;
	if (temp[1] != NULL)
		color = convert_(temp[1]);
	else
		color = my_mlx_create_trgb(0, 230, 255, 51);
	pt.color = color;
	pt.is_last = is_last;
	return (pt);
}

int	get_nb_points(t_point *points)
{
	int	i;

	i = 0;
	while (points[i].is_last == 0)
		i++;
	return (i);
}

static int	*init_vars(char ***values, t_map map, t_point **pts)
{
	int	*index;

	index = (int *) malloc(sizeof(int) * 4);
	*values = (char **) malloc(sizeof(char *) * (map.height + 1));
	*pts = (t_point *) malloc(sizeof(t_point) * (map.height * map.width));
	if (!*values || !*pts || !index)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	return (index);
}

t_point	*init_map_points(const t_map map)
{
	char	**values;
	t_point	*pts;
	char	*temp;
	int		*idx;

	idx = init_vars(&values, map, &pts);
	while (map.map_temp[idx[0]])
	{
		temp = map.map_temp[idx[0]];
		remove_nl(temp);
		values = ft_split(temp, ' ');
		values = mem_set_values(values, map);
		idx[1] = -1;
		while (values[++idx[1]])
		{
			pts[idx[2]] = create_point(idx[1], idx[0], values[idx[1]], 0);
			free(values[idx[1]]);
			idx[2]++;
		}
		free(values);
		free(temp);
		idx[0]++;
	}
	pts[idx[2]] = create_point(-10, -10, "0,OxFFFFFF", 1);
	return (free(idx), pts);
}
