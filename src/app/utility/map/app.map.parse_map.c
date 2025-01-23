/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.map.parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:04:18 by mbah              #+#    #+#             */
/*   Updated: 2025/01/23 01:43:14 by mbah             ###   ########.fr       */
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
		(exit(FALSE));
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

int	ft_countword(const char *str, char sep)
{
	int	count;
	int	i;

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

int	get_map_width(char **map)
{
	return (ft_countword(map[0], ' '));
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i += 1;
	return (i);
}
