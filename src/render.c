/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:25:54 by claferna          #+#    #+#             */
/*   Updated: 2024/04/17 18:00:18 by claferna         ###   ########.fr       */
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

	x = 1;
	while (x <= map->width)
	{
		y = 1;
		while (y <= map->height)
		{
			initialize_coords(&coords, x, y, 0);
			initialize_coords(&coords_x, x, y, 1);
			initialize_coords(&coords_y, x, y, 2);
			coords.color = 0xFF0000;
			if (x <= map->width -1)
				join_dots(&coords, &coords_x, map, img);
			if (y <= map->height -1)
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
	float	x_aux;
	float	y_aux;
	float	max;

	coords_to_isometric(a, b, map->matrix);
	x_diff = abs(b->x_scaled - a->x_scaled);
	y_diff = abs(b->y_scaled - a->y_scaled);
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
	x_aux = a->x_scaled * 20;
	y_aux = a->y_scaled * 20;
//	float x_aux_1 = b->x_scaled * 20;
//	float y_aux_1 = b->x_scaled * 20;
	while (max--)//(int) (x_aux - x_aux_1) || (int) (y_aux - y_aux_1))
	{
		my_mlx_pixel_put(img, (int)x_aux, (int)y_aux, a->color);
		x_aux += x_diff;
		y_aux += y_diff;
	}
}

int	main(void)
{
	t_data	img;
	t_map	map;

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 1280, 920, "FDF");
	img.img = mlx_new_image(img.mlx_ptr, 1280, 920);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	initialize_matrix(&map, "test_maps/42.fdf");
	render(&img, &map);
	mlx_hook(img.win_ptr, KEY_PRESS, 0, close_window, NULL);
	mlx_hook(img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_loop(img.mlx_ptr);
}
