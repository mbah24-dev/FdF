/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:38:26 by mbah              #+#    #+#             */
/*   Updated: 2025/01/29 16:05:48 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_height(t_fdf *fdf, const char *path)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate(fdf, "OPEN ERR: File not found", 1);
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
	return (close_fd(fdf, fd), height);
}

static int	get_map_width(t_fdf *fdf, const char *path)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate(fdf, "OPEN ERR: File not found", 1);
	width = 0;
	line = get_next_line(fd);
	if (!line || *line == '\0')
		terminate(fdf, "MAP ERR: The map format is invalid.", 1);
	i = -1;
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\n'))
			width++;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	return (close_fd(fdf, fd), width);
}

static void	get_line_values(t_fdf *fdf, int **values, char *line, int width)
{
	int		i;
	int		j;
	char	**numbers;

	numbers = ft_split(line, ' ');
	if (!numbers || !values || !fdf)
		free_split(fdf, numbers, fdf->fd, line);
	i = -1;
	while (numbers[++i] && i < width)
	{
		values[i] = ft_calloc(sizeof(int), 2);
		if (!values[i])
			free_split(fdf, numbers, fdf->fd, line);
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

static void	get_min_max_z_values(t_fdf *fdf, t_map *map, int nb_line, int fd)
{
	int	i;
	int	j;

	i = -1;
	if (!map->map_coord || nb_line != map->height - 1)
		terminate(fdf, "SEGFAULT ERR: ", 1);
	map->z_min = map->map_coord[0][0][0];
	map->z_max = map->map_coord[0][0][0];
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_coord[i][j][0] < map->z_min)
				map->z_min = map->map_coord[i][j][0];
			if (map->map_coord[i][j][0] > map->z_max)
				map->z_max = map->map_coord[i][j][0];
		}
	}
	close_fd(fdf, fd);
}

void	check_the_map(t_fdf *fdf, t_map *map, const char *path)
{
	int		i;
	char	*line;

	map->width = get_map_width(fdf, path);
	map->height = get_map_height(fdf, path);
	fdf->fd = open(path, O_RDONLY);
	if (fdf->fd == -1 || !map->width || !map->height)
		terminate(fdf, "OPEN ERR:", 1);
	i = -1;
	map->map_coord = (int ***) ft_calloc(sizeof(int **), map->height);
	if (!map->map_coord)
		terminate(fdf, "MALLOC ERR: Memory allocation failed. ", 1);
	while (1)
	{
		line = get_next_line(fdf->fd);
		if (!line || *line == '\0')
			break ;
		map->map_coord[++i] = ft_calloc(sizeof(int *), map->width);
		if (!map->map_coord[i])
			free_split(fdf, 0, fdf->fd, line);
		get_line_values(fdf, map->map_coord[i], line, map->width);
		free(line);
	}
	get_min_max_z_values(fdf, map, i, fdf->fd);
}
