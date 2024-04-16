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
int	select_color(t_coords *a, t_coords *b, t_map *map)
{
	int	a_x = a->x -1;
	int	a_y = a->y -1;
    int b_x = b->x -1;
    int b_y = b->y -1;
	//int	aux_z;
    printf("AAA X: %d Y: %d --> \n", a_x, a_y);//map->matrix[a_y -20][a_x - 20]);
    printf("BBB X: %d Y: %d --> \n", b_x , b_y); //map->matrix[a_y -20][a_x - 20]);
    printf("\n%d\n", map->matrix[a_y][a_x]);
    return (0);
/*
	aux_x = x - 20;
	aux_y = y - 20;
	aux_z = map->matrix[x][y];
	if (aux_z > 0)
		return (0xFF0000);
	return (0x0000FF);*/
}
