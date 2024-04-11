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
void    scale_coords(t_coords coords_a, t_coords coords_b)
{
    
}

/*
angulo es x
*/
void isometric()
{
    x = (x  - y) * cos(angle);
    y = (x + y ) * sin(angle) - z;
}