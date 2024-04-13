
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:54:14 by claferna          #+#    #+#             */
/*   Updated: 2024/04/13 18:56:58 by claferna         ###   ########.fr       */
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
int get_matrix_height(char *file_name)
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

void	process_line(char *line, int  *z_matrix)
{
	char **items;
	int		num;
	int		i;

	i = 0;
	items = ft_split(line, ' ');
	if (items)
	{
		while(items[i])
		{
			num = ft_atoi(items[i]);
			z_matrix[i] = num;
			free(items[i]);
			i++;
		}
	}
}

/*
** DESC: The 'fill_matrix' function fills the matrix with the map info.
*/
void	fill_matrix(t_map *map)
{
	char *line;
	
	map->matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	int i = 0;
	while (i <= map->height)
		map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	int fd = open(map->filename, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		process_line(line, map->matrix[i]);
		free(line);
		i++;
	}
	map->matrix[i] = 0; 
	if (fd == -1)
		return ;
	close(fd);
}

void	prepare_matrix(t_map *map)
{
	map->filename = "test_maps/42.fdf";
	printf("El nombre del mapa: %s\n", map->filename);
	map->height	= get_matrix_height(map->filename);
	printf("La altura del mapa: %d\n", map->height);
	map->width = get_matrix_width(map->filename);
	printf("La anchura del mapa: %d\n", map->width);
	fill_matrix(map);
}

int main()
{
	t_map map;
	prepare_matrix(&map);
	/*
	char *file = "test_maps/42.fdf";
	t_map	map;
	map.height = get_matrix_height(file);
	map.width = get_matrix_width(file);
	printf("Height: %d\n", map.height);
	printf("Width: %d", map.width);
	fill_matrix(file, &map);*/
   	printf("%d", map.matrix[8][3]);	
}	

