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