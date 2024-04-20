<<<<<<< HEAD
#include "../include/fdf.h"
/*
** DESC: Gets the max value from two numbers
*/
int	get_max(int num1, int num2)
=======
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
>>>>>>> local
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

/*
<<<<<<< HEAD
** DESC: Scaletes the coordinates.
*/
void    scale_coords(t_coords *coords_a, t_coords *coords_b, int scale)
{
    /*(*coords_a).x*/
    coords_a->x *= scale;
    coords_a->y *= scale;
    coords_b->x *= scale;
    coords_b->y *= scale;
}

/*
** DESC: Convert coords to isometric proyection.
*/
void to_isometric(t_coords *coords_a, t_coords *coords_b, char **matrix)
{
    int a_z;
    int b_z;

    a_z = matrix[coords_a.x][coords_a.y];
    b_z = matrix[coords_b.x][coords_b.y];
    coords_a->x = (coords_a->x  - coords_a->y) * cos(0.5);
    coords_a->y = (coords_a->x + coords_a->y ) * sin(0.5) - a_z;

    coords_b->x = (coords_b->x  - coords_a->y) * cos(0.5);
    coords_b->y = (coords_a->x + coords_a->y ) * sin(0.5) - b_z;
}
=======
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
>>>>>>> local
