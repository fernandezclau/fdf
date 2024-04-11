
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:54:14 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 20:57:52 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

void	process_line(char *line, char *z_matrix)
{
	char	**items;
	int		i;

	i = 0;
	items = ft_split(line, ' ');
	while(items[i])
	{
		*z_matrix[i] = ft_atoi(items[i]);
		free(items[i]);
		i++;
	}
}

void	fill_matrix(char *file_name, int width, int height)
{
	int	**z_matrix;
	char buffer[1];
	char *line;
	
	z_matrix = (int **)malloc(sizeof(int) * (height + 1));
	int i = 0;
	while (i <= height)
		z_matrix[i++] = (int *)malloc(sizeof(int) * (width + 1));
	int fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		process_line(line, z_matrix[i])
		free(line);
		i++;
	}
	z_matrix[i] = '\0'; 
	if (fd == -1)
		return ;
	i = 0;
	close(fd);
}

int main()
{
	char *file = "test_maps/42.fdf";
	int height;		// width of the matrix --> struct
	int width;		// height of the matrix --> struct

	height = get_matrix_height(file);
	width = get_matrix_width(file);
	printf("Height: %d\n", height);
	printf("Width: %d", width);
	get_values(file, width, height);
}	

