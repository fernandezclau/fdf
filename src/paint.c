/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/14 19:28:43 by claferna         ###   ########.fr       */
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
	while(x < map->width) 
	{
		y = 0;
		while(y < map->height)
		{
			initialize_coords(&coords, x  + 25, y  + 25);
			initialize_coords(&coords_x, x  + 50, y + 25);
			initialize_coords(&coords_y, x + 25, y + 50);
			printf("X %d, Y %d\n", coords.x, coords.y);
			printf("X_x %d, Y_x %d\n", coords_x.x, coords_x.y);
			printf("X_y %d, Y_y %d\n", coords_y.x, coords_y.y);
			printf("%d", x);
			if (x < map->width - 1)
				join_dots(&coords, &coords_x, map, img);
			if (y < map->height - 1)
				join_dots(&coords, &coords_y, map, img);
			else
				y++;
			y++;
		}
		x++;
	}
}

void join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img) {
    
	float	x_diff;
	float	y_diff;
	float	max;

	x_diff = abs(b->x - a->x);
	y_diff = abs(b->y - a->y);	
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
    
	float x = a->x * 15;
    float y = a->y * 15;

    for (int i = 0; i < max +1; i++) {
        my_mlx_pixel_put(img, (int)x, (int)y, 0xFFFFFF);
        x += x_diff;
        y += y_diff;
    }
	printf("%d", map->width);
}


int main(void)
{
//	void	*mlx;
//	void	*mlx_win;
	t_data	img;
	t_map map;

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 1080, 1080, "FDF");
	img.img = mlx_new_image(img.mlx_ptr, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	map.height = map.height = 2;
	initialize_matrix(&map);	
	paint(&img, &map);
/*
	int y;
	int x = 0;
	while (x < map.width)
	{
		y = 0;
		while (y < map.height)
		{
			if (y < map.height - 1)
				join_dotis(x, y, x + 1,y, &map, &img);
			if (x < map.width - 1)
				join_dotis(x, y, x , y +1 , &map, &img);
			else
				break;
			y++;
		}
		x++;
	} */
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_loop(img.mlx_ptr);
}
