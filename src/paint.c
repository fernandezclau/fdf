/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/14 18:55:58 by claferna         ###   ########.fr       */
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
			initialize_coords(&coords, x + 25, y + 25);
			initialize_coords(&coords_x, x + 50, y + 25);
			initialize_coords(&coords_y, x + 25, y + 50);
			printf("X %d, Y %d\n", coords.x, coords.y);
			printf("X_x %d, Y_x %d\n", coords_x.x, coords_x.y);
			printf("X_y %d, Y_y %d\n", coords_y.x, coords_y.y);
			printf("%d", map->height);
			if (x < map->height -1)
				join_dots(&coords, &coords_x, map, img);
			if (y < map->width - 1)
				join_dots(&coords, &coords_y, map, img);
			y++;
		}
		x++;
	}
}

/*
** DES: Join two dots in the map
*/

void	join_dotis(float x, float y, float x_1, float y_1, t_map *map, t_data *img)
{
	float x_diff;
	float y_diff;
	int	max;

	x_diff = x_1 - x; 		//Difference between Xs
	y_diff = y_1 - y; 		//Difference between Ys
	printf("%f, %f", x_diff, y_diff);
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
	printf("%d", map->width);	
	x *= 20;
   	y *= 20;
	x_1 *= 20;
	y_1 *= 20;	
	while (1)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		if (x - x_diff == x_1 && y - y_diff == y_1)
			break ;
		x += x_diff;
		y += y_diff;
	}
}


void join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img) {
    // Calcular las diferencias en las coordenadas x e y
	float dx = b->x - a->x;
    float dy = b->y - a->y;

    // Determinar el valor absoluto de las diferencias
    float abs_dx = fabsf(dx);
    float abs_dy = fabsf(dy);

    // Determinar la dirección de los pasos en x e y
    int step_x = dx > 0 ? 1 : -1;
    int step_y = dy > 0 ? 1 : -1;

    // Calcular el máximo entre las diferencias absolutas
    float max_diff = abs_dx > abs_dy ? abs_dx : abs_dy;

    // Calcular los incrementos para moverse de un píxel a otro
    float x_inc = abs_dx / max_diff;
    float y_inc = abs_dy / max_diff;
	printf("INC X%f", x_inc);
	printf("INC Y %f", y_inc);
    // Inicializar las coordenadas actuales
    float x = a->x * 20;
    float y = a->y * 20;

    // Dibujar píxel por píxel utilizando el algoritmo de Bresenham
    for (int i = 0; i < max_diff; i++) {
        my_mlx_pixel_put(img, (int)x, (int)y, 0xFFFFFF);

        // Mover a la siguiente posición utilizando los incrementos
        x += step_x * x_inc;
        y += step_y * y_inc;
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
