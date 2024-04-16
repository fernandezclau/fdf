/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/15 18:38:32 by claferna         ###   ########.fr       */
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
	
	x = 1;	
	while(x <= map->width)
	{
		y = 1;
		while(y <= map->height)
		{
			int z = map->matrix[y - 1][x - 1];
            printf("%d \n", z);
			initialize_coords(&coords, x, y, 0);
			initialize_coords(&coords_x, x, y, 1);
			initialize_coords(&coords_y, x, y, 2);
			if (z)
				coords.color = 0xFFFFFF;
			else 
				coords.color = 0xFF0000;
			if (x <= map->width -1)
				join_dots(&coords, &coords_x, map, img);
			if (y <= map->height -1)
				join_dots(&coords, &coords_y, map, img);
			y++;
		}
        printf("------------------------\n");
		x++;
	}
}

void join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img) {
    
	float	x_diff;
	float	y_diff;
	float	x_aux;
	float	y_aux;
	float	max;
	//int		color;

	x_diff = abs(b->x_scaled - a->x_scaled);
	y_diff = abs(b->y_scaled - a->y_scaled);
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
    x_aux = a->x;
    y_aux = a->y;
    //color = select_color(a, b, map);
	x_aux = a->x_scaled * 20;
    y_aux = a->y_scaled * 20;
    while (max--) {
        my_mlx_pixel_put(img, (int)x_aux, (int)y_aux, a->color);
        x_aux += x_diff;
        y_aux += y_diff;
    }
    printf("\n%d\n", map->height);
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
	initialize_matrix(&map);
	//write(1, &(map.matrix[0][0]), 1);
	//printf("%d\n", map.matrix[0][0]);	
	paint(&img, &map);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_loop(img.mlx_ptr);
}
