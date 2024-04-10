
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:54:14 by claferna          #+#    #+#             */
/*   Updated: 2024/04/09 20:39:13 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	get_matrix_width(char *file_name)
{
	int	fd;
	int	read_bytes;
	char	*buffer;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	buffer = (char *)malloc(sizeof(char));
	int width = 0;
	while (*buffer != '\n')
	{
		read_bytes = read(fd, buffer, 1);
		if (*buffer != ' ')
			width++;
	}
	close(fd);
	return (width--);
}

int get_matrix_height(char *file_name)
{
	int		fd;
	int		read_bytes;
	char	buffer[1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	int height = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (*buffer == '\n')
			height++;
	}
	close(fd);
	return (height);
}
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
void	get_values(char *file_name, int width, int height)
{
	int	**z_matrix;
	char buffer[1];

	z_matrix = (int **)malloc(sizeof(int) * (height + 1));
	int i = 0;
	while (i <= height)
		z_matrix[i++] = (int *)malloc(sizeof(int) * (width + 1));
	int fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	printf("\n");
	while (read(fd, buffer, 1) > 0)
	{
		//get_next_line();
		//split
		//atoi
	}
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

