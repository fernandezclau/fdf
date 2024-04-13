/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/13 09:31:43 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'paint' function represents the 
*/
void	paint(t_data *img, t_map *map)
{
	int	x;
	int	y;
	t_coords	coords;
	t_coords	coords_x;
	t_coords	coords_y;

	x = 0;
	while(x < map->height)
	{
		y = 0;
		while(y < map->width)
		{
			initialize_coords(&coords, x, y);
			initialize_coords(&coords_x, x + 1, y);
			initialize_coords(&coords_y, x, y + 1);
			if (x < map->width - 1)
				join_dots(&coords, &coords_x, map, img);
			if (y < map->height - 1)
				join_dots(&coords, &coords_y, map, img);
			y++;
		}
		x++;
	}
}

/*
** DES: Join two dots in the map
*/
void	join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img)
{
	int	x_diff;
	int	y_diff;
	int	max;

	x_diff = b->x - a->x; 		//Difference between Xs
	y_diff = b->y - a->y; 		//Difference between Ys
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
	scale_coords(a, b, 20);
	coords_to_isometric(a, b, map->matrix);
	while ((b->x - a->x) || (b->y - a->y))
	{
		my_mlx_pixel_put(img, a->x, a->y, 0x00FF0000);
		a->x += x_diff;
		a->y += y_diff;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	//join_dots(2, 3, 6, 7, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
