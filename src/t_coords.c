/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:14:22 by claferna          #+#    #+#             */
/*   Updated: 2024/04/17 18:00:15 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#define ANGLE 0.523539

/*
** DESC: The 'initialize_coords' function initializes the members of the 
** 't_coord' struct variable.
** 
** OPTIONS: 
**			dis DEFAULT --> Initialize (x, y) 
**			dis 2 		--> Initialize (x + 1, y)
**			dis 3 		--> Initialize (x, y + 1)
*/
void	initialize_coords(t_coords *coord, int _x, int _y, int dis)
{
	if (dis == 1)
	{
		coord->x_scaled = _x + 20;
		coord->y_scaled = _y + 10;
		coord->x = _x + 1;
		coord->y = _y;
	}
	else if (dis == 2)
	{
		coord->x_scaled = _x + 10;
		coord->y_scaled = _y + 20;
		coord->x = _x;
		coord->y = _y + 1;
	}
	else
	{
		coord->x_scaled = _x + 10;
		coord->y_scaled = _y + 10;
		coord->x = _x;
		coord->y = _y;
	}
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
	int	a_z;
	int	b_z;

    a_z = matrix[a->y][a->x];
    b_z = matrix[b->y][b->x];
    a->x_scaled= (a->x - a->y) * cos(ANGLE);
    a->y_scaled = (a->x + a->y) * sin(ANGLE) - (a_z);
    b->x_scaled = (b->x - b->y) * cos(ANGLE);
    b->y_scaled = (b->x + b->y) * sin(ANGLE)- (b_z);
}
