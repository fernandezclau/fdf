/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:29:28 by claferna          #+#    #+#             */
/*   Updated: 2024/04/23 19:46:16 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'get_matrix_width' function gets the width of the map.
*/
int	get_matrix_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;
	char	**split;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	line = ft_strtrim(line, " ");
	split = ft_split(line, ' ');
	width = 0;
	if (split)
		while (split[width] != NULL)
			width++;
	close(fd);
	return (width);
}

/*
** DESC: The 'get_matrix_height' function gets the height of a map.
*/
int	get_matrix_height(char *file_name)
{
	int		fd;
	char	buffer[1];
	int		height;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	height = 0;
	while (read(fd, buffer, 1) > 0)
		if (*buffer == '\n')
			height++;
	close(fd);
	return (height);
}

/*
** DESC: The 'fill_matrix' function fills the matrix with the map info.
*/
void	fill_matrix(t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	map->matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	i = 0;
	while (i <= map->height)
		map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	fd = open(map->filename, O_RDONLY);
	if (!fd)
		return ;
	i = 0;
	while (i < map->height)
	{
		line = (char *)malloc(sizeof(char) * map->width);
		if (!line)
			return ;
		line = get_next_line(fd);
		process_line(line, map->matrix[i]);
		free(line);
		i++;
	}
	map->matrix[i] = 0;
	if (close(fd))
		return ;
}

/*
** DESC: The 'intialize_matrix' function initializes all the members of the
** 'map' struct variable.
*/
void	initialize_matrix(t_map *map, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_printf("That file does not exist .-.");
	else
		close(fd);
	map->filename = filename;
	ft_printf("El nombre del mapa: %s\n", map->filename);
	map->height = get_matrix_height(map->filename);
	ft_printf("La altura del mapa: %d\n", map->height);
	map->width = get_matrix_width(map->filename);
	ft_printf("La anchura del mapa: %d\n", map->width);
	map->zoom = 10;
	ft_printf("El zoom está establecido en: %d", map->zoom);
	map->move_x = 10;
	map->move_y = 10;
	fill_matrix(map);
	ft_printf("The file has been read");
}
/*
int main()
{
	t_map map;
	initialize_matrix(&map);
	int i = 0;
	int j;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{	
   			printf(" %d ", map.matrix[i][j]);	
			if (map.matrix[i][j] == ' ')
				printf("nooo");
			j++;
		}
		printf("\n");
		i++;
	}
}*/
