/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:03 by claferna          #+#    #+#             */
/*   Updated: 2024/04/16 20:10:26 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: Gets the max value from two numbers
*/
float	get_max(float num1, float num2)
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
void	process_line(char *line, int *z_matrix)
{
	char	**items;
	int		num;
	int		i;

	i = 0;
	items = ft_split(line, ' ');
	if (items)
	{
		while (items[i])
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
/*
int	select_color(t_coords *a, t_coords *b, t_map *map)
{
	int	a_x = a->x -1;
	int	a_y = a->y -1;
    int b_x = b->x -1;
    int b_y = b->y -1;

    float x_iso = ((b_x - a_x) - (b_y - a_y)) * 20;
    float y_iso = ((b_x - a_x) +(b_y - a_y)) * 20 / 2 - (b_z - a_z);
    printf("XISO : %f, YISO: %f:", x_iso, y_iso);
    //int	aux_z;
    //printf("AAA X: %d Y: %d --> \n", a_x, a_y);
    //printf("BBB X: %d Y: %d --> \n", b_x , b_y);
    printf("\n%d\n", map->matrix[a_y][a_x]);
    printf("\n%d\n", map->matrix[b_y][b_x]);
    return (0);

	aux_x = x - 20;
	aux_y = y - 20;
	aux_z = map->matrix[x][y];
	if (aux_z > 0)
		return (0xFF0000);
	return (0x0000FF);
}*/
