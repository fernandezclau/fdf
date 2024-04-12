#include "../include/fdf.h"

#define ANGLE 0.5

/*
** DESC: The 'initialize_coords' function initializes the members of the 
** 't_coord' struct variable.
*/
void initialize_coords(t_coords *coord, float _x, float _y)
{
	coord->x = _x;
	coord->y = _y;
}

/*
** DESC: The 'scale_coords' funtcion scalates the given coordinates
*/
void	scale_coords(t_coords *a, t_coords *b, int scale)
{
	a->x *= scale;
	a->y *= scale;
	b->x *= scale;
	b->y *= scale;
}

/*
** DESC: The 'coord_to_isometric' functions converts the given coordinates to
** isometric proyection
*/
void	coords_to_isometric(t_coords *a, t_coords *b, int **matrix)
{
	int a_z;
	int b_z;

	a_z = matrix[a->x][a->y];
	b_z = matrix[b->x][b->y];
	a->x = (a->x - a->y) * cos(ANGLE);
	a->y = (a->x + a->y) * sin(ANGLE) - a_z;
	b->x = (b->x - b->y) * cos(ANGLE);
	b->y = (b->x + b->y) * sin(ANGLE) - b_z;
}
