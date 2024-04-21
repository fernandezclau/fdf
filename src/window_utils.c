/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:55:29 by claferna          #+#    #+#             */
/*   Updated: 2024/04/21 17:32:53 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'close_window' function exits the program with the 'ESC' key.
*/
int	close_window(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == 122)
		map->move_x += 5;
	else if (keycode == PLUS_KEY)
		map->zoom += 10;
	else if (keycode == MINUS_KEY)
		if (map->zoom > 5)
			map->zoom -= 5;
	mlx_destroy_image(map->img.mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(map->img.mlx_ptr, WIDTH, HEIGHT);
	render(&map->img, map);
	mlx_put_image_to_window(map->img.mlx_ptr, map->img.win_ptr, \
			map->img.img, 1, 1);
	return (0);
}

int	key_hold(int keycode, t_map *map)
{
	if (keycode == W_KEY)
		printf("asd%d", map->width);
	return (0);
}

/*
** DESC: The 'close_window_x' funtion exits the program with the 'x' button.
*/
int	close_window_x(void *param)
{
	exit(0);
	printf("%p", param);
	return (0);
}

/*
** DESC: The 'my_mlx_pixel_put' function optimises the representation of bytes
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}
