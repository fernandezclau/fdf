/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:14:22 by claferna          #+#    #+#             */
/*   Updated: 2024/04/23 19:17:49 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
		coord->x_scaled = _x;
		coord->y_scaled = _y;
		coord->x = _x + 1;
		coord->y = _y;
	}
	else if (dis == 2)
	{
		coord->x_scaled = _x;
		coord->y_scaled = _y;
		coord->x = _x;
		coord->y = _y + 1;
	}
	else
	{
		coord->x_scaled = _x;
		coord->y_scaled = _y;
		coord->x = _x;
		coord->y = _y;
	}
}

/*
** DESC: The 'scale_coords' funtcion scalates the given coordinates
*/
void	scale_coords(t_coords *a, t_coords *b, int scale)
{
	a->x_scaled *= scale;
	a->y_scaled *= scale;
	b->x_scaled *= scale;
	b->y_scaled *= scale;
}

/*
** DESC: The 'coord_to_isometric' functions converts the given coordinates to
** isometric proyection
*/
void	coords_to_isometric(t_coords *a, t_coords *b, t_map *map)
{
	int	a_z;
	int	b_z;

	a_z = map->matrix[a->y][a->x];
	b_z = map->matrix[b->y][b->x];
	if (a_z > 0 && b_z > 0)
		a->color = 0x004765;
	else if (a_z > 0 || b_z > 0)
		a->color = 0x581845;
	else
		a->color = 0xB91B58;
	a->x_scaled = ((a->x) - (a->y)) * cos(0.8660254) + map->move_x;
	a->y_scaled = ((a->x) + (a->y)) * sin(ANGLE) - (a_z) + map->move_y;
	b->x_scaled = ((b->x) - (b->y)) * cos(0.8660254) + map->move_x;
	b->y_scaled = ((b->x) + (b->y)) * sin(ANGLE)- (b_z) + map->move_y;
}
