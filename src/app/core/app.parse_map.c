/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:38:26 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 01:40:08 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	get_map_height(const char *path)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate("OPEN ERR: File not found", 1);
	height = 0;
	line = "";
	while (1)
	{
		line = get_next_line(fd);
		if (!line || *line == '\0')
			break ;
		height++;
		free(line);
	}
	free(line);
	return (close_fd(fd), height);
}

static int	get_map_width(const char *path)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate("OPEN ERR: File not found", 1);
	width = 0;
	line = get_next_line(fd);
	if (!line || *line == '\0')
		terminate("MAP ERR: The map format is invalid.", 1);
	i = -1;
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	return (close_fd(fd), width);
}

static void	get_line_values(int **values, char *line, int width)
{
	int		i;
	int		j;
	char	**numbers;

	numbers = ft_split(line, ' ');
	i = -1;
	while (numbers[++i] && i < width)
	{
		values[i] = malloc(sizeof(int) * 3);
		if (!values[i])
			terminate("MALLOC ERR: Memory allocation failed. ", 1);
		values[i][0] = ft_atoi(numbers[i]);
		j = 0;
		while (numbers[i][j] && numbers[i][j] != ',')
			j++;
		if (numbers[i][j] == ',')
			values[i][1] = convert_(&numbers[i][++j]);
		else
			values[i][1] = -1;
		free(numbers[i]);
	}
	free(numbers);
}

static void	get_min_max_z_values(t_map *map, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	if (!map->map_coord)
		return ;
	map->z_min = map->map_coord[0][0][0];
	map->z_max = map->map_coord[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_coord[i][j][0] < map->z_min)
				map->z_min = map->map_coord[i][j][0];
			if (map->map_coord[i][j][0] > map->z_max)
				map->z_max = map->map_coord[i][j][0];
			j++;
		}
		i++;
	}
	free(line);
	close_fd(fd);
}

void	check_the_map(t_map *map, const char *path)
{
	int		i;
	char	*line;
	int		fd;

	map->width = get_map_width(path);
	map->height = get_map_height(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate("OPEN ERR: File not found", 1);
	i = -1;
	map->map_coord = (int ***) malloc(sizeof(int **) * map->height);
	if (!map->map_coord)
		terminate("MALLOC ERR: Memory allocation failed. ", 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || *line == '\0')
			break ;
		map->map_coord[++i] = malloc(sizeof(int *) * map->width);
		if (!map->map_coord[i])
			terminate("MALLOC ERR: Memory allocation failed. ", 1);
		get_line_values(map->map_coord[i], line, map->width);
		free(line);
	}
	get_min_max_z_values(map, line, fd);
}
