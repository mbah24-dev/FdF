/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:04:18 by mbah              #+#    #+#             */
/*   Updated: 2025/01/20 21:08:55 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	**get_the_map(char *path, char *argv_1)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	if (fd < 0 || ft_strncmp(argv_1, "", 2) == 0)
	{
		ft_putstr_fd("Error: fichier introuvable \n", 1);
		(exit(ERROR));
	}
	while (get_next_line(fd) != (NULL))
		i++;
	fd = open(path, O_RDONLY);
	map = (char **) malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (1)
	{
		map[++i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
	}
	return (map);
}

size_t	ft_countword(const char *str, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count += 1;
			while (str[i] && str[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (count);
}

size_t	get_map_width(char **map)
{
	return (ft_countword(map[0], ' '));
}

size_t	get_map_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i += 1;
	return (i);
}

char	***get_map_content(char **map, const char map_sep)
{
	char	***values;
	size_t	map_height;
	int		i;

	map_height = get_map_height(map);
	values = (char ***) malloc(sizeof(char **) * (map_height + 1));
	if (!values)
		return (NULL);
	i = -1;
	while (map[++i])
		values[i] = ft_split(map[i], map_sep);
	values[i] = (NULL);
	return (values);
}
