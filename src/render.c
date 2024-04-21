/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:25:54 by claferna          #+#    #+#             */
/*   Updated: 2024/04/21 17:30:47 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'paint' function represents the 
*/
void	render(t_data *img, t_map *map)
{
	t_coords	coords;
	t_coords	coords_x;
	t_coords	coords_y;
	int			x;
	int			y;

	x = 0;
	while (x <= map->width -1)
	{
		y = 0;
		while (y <= map->height -1)
		{
			initialize_coords(&coords, x, y, 0);
			initialize_coords(&coords_x, x, y, 1);
			initialize_coords(&coords_y, x, y, 2);
			if (x < map->width -1)
				join_dots(&coords, &coords_x, map, img);
			if (y < map->height -1)
				join_dots(&coords, &coords_y, map, img);
			y++;
		}
		x++;
	}
}

/*
** DESC: The 'join_dots' funtcion joins two points in a cartesian plane.
*/
void	join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img)
{
	float	x_diff;
	float	y_diff;
	float	max;

	coords_to_isometric(a, b, map);
	x_diff = (b->x_scaled) - (a->x_scaled);
	y_diff = (b->y_scaled) - (a->y_scaled);
	max = get_max(fabsf(x_diff), fabsf(y_diff));
	x_diff /= max;
	y_diff /= max;
	scale_coords(a, b, map->zoom);
	while ((int)(a->x_scaled - b->x_scaled) || \
			(int)(a->y_scaled - b->y_scaled))
	{
		if ((a->x_scaled > 0 && a->x_scaled < WIDTH) \
				&& (a->y_scaled > 0 && a->y_scaled < HEIGHT))
			my_mlx_pixel_put(img, (int)a->x_scaled, \
					(int)a->y_scaled, a->color);
		a->x_scaled += x_diff;
		a->y_scaled += y_diff;
	}
}
