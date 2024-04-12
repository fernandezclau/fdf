/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 18:34:48 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
			coords.initialice(x, y);
			coords_x.initialice(x + 1, y);
			coords_y.initialice(x, y + 1);
			if (x < map->width - 1)
				join_dots(coords, coords_x, &map, &img);
			if (y < map->height - 1)
				join_dots(coords, coords_y, &map, &img);
			y++;
		}
		x++;
	}
}

/*
** DESCRIPTION: Join two dots in the map
*/
void	join_dots(t_coords *coords_a, t_coords *coords_b, t_map *map, t_data *img)
{
	int	x_diff;
	int	y_diff;
	int	max;

	x_diff = coords_b.x - coords_a.x; 		//Difference between Xs
	y_diff = coords_b.y - coords_a.y; 		//Difference between Ys
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
	scale_coords(&coords_a, &coords_b, 20);
	to_isometric(&coords_a, &coords_b, map.matrix);
	while ((coords_b.x - coords_a.x) || (coords_b.y - coords_a.y))
	{
		my_mlx_pixel_put(img, coords_a.x, coords_a.y, 0x00FF0000);
		coords_a.x += x_diff;
		coords_a.y += y_diff;
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
	while (/* condition */)
	{
		/* code */
	}
	
	join_dots(2, 3, 6, 7, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
