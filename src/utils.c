#include "../include/fdf.h"
/*
** DESC: Gets the max value from two numbers
*/
int	get_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

/*
** DESC: The 'manage_errors' function prints an error message.
*/
int	manage_error(char *message)
{
	ft_printf("%s", message);
	return (-1);
}

/*
** DESC: The 'process_line' process a line pouring it into the matrix.
*/
void	process_line(char *line, int  *z_matrix)
{
	char	**items;
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
** DESC: The 'select_color' changes the color of the rendered bytes.
*/
int	select_color(int x, int y, t_map *map)
{
	int	aux_x;
	int	aux_y;
	int	aux_z;

	aux_x = x - 20;
	aux_y = y - 20;
	aux_z = map->matrix[x][y];
	if (aux_z > 0)
		return (0xFF0000);
	return (0x0000FF);
}
