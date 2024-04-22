/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:55:29 by claferna          #+#    #+#             */
/*   Updated: 2024/04/22 20:58:10 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
/*
** DESC: The 'initialize' function initializes all the hooks in the program.
*/
/*
void	initiliaze_hooks(t_map *map)
{
	mlx_hook(map->img.win_ptr, KEY_PRESS, 0, close_window, &map);
	mlx_hook(map->img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_hook(map->img.win_ptr, KEY_PRESS, 0, move, &map);
}
*/
/*
** DESC: The 'close_window' function exits the program with the 'ESC' key.
*/
int	close_window(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
	{
		//printf("%d", map->width);
		exit (0);
	}
	return (0);
}

/*
** DESC: The 'close_window_x' function exits the program with the 'x' function.
*/
int	close_window_x(void)
{
	//liberar
	exit(0);
	return (0);
}

/*
** DESC: The 'move' function allows to move the figure around the map.
*/
int	move(int keycode, t_map *map)
{
	if (keycode == PLUS_KEY)
	{
		if (map->zoom < 100)
			map->zoom += 2;
	}
	else if (keycode == MINUS_KEY)
	{
		if (map->zoom > 2)
			map->zoom -= 2;
	}
	else if (keycode == W_KEY)
		map->move_y -= 5;
	else if (keycode == S_KEY)
		map->move_y += 5;
	else if (keycode == D_KEY)
		map->move_x += 5;
	else if (keycode == A_KEY)
		map->move_x -= 5;
	destroy_and_render(map);
	return (0);
}
/*
** DESC: The 'close_window' function exits the program with the 'ESC' key.
*/
/*int	close_window(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		exit(0);
	else if (keycode == PLUS_KEY)
	{	
		if (map->zoom < 100)
			map->zoom += 5;
	}
	else if (keycode == MINUS_KEY)
	{
		if (map->zoom > 5)
			map->zoom -= 5;
	}
	else if (keycode == W_KEY)
		map->move_y -= 5;
	else if (keycode == S_KEY)
		map->move_y += 5;
	else if (keycode == D_KEY)
		map->move_x += 5;
	else if (keycode == A_KEY)
		map->move_x -= 5;
	destroy_and_render(map);
	
	mlx_destroy_image(map->img.mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(map->img.mlx_ptr, WIDTH, HEIGHT);
	render(&map->img, map);
	mlx_put_image_to_window(map->img.mlx_ptr, map->img.win_ptr, \
			map->img.img, 1, 1);
	return (0);
}*/

/*
** DESC: The 'close_window_x' funtion exits the program with the 'x' button.
*/
/*int	close_window_x(void *param)
{
	exit(0);
	printf("%p", param);
	return (0);
}*/

/*
** DESC: The 'my_mlx_pixel_put' function optimises the representation of bytes
*//*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}*/
