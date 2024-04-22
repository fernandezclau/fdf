/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/22 20:58:25 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argv, char **argc)
{
	t_map	map;

	if (argv != 2)
		return (manage_error("Please, enter a map :)\n"));
	map.zoom = 10;
	initialize_matrix(&map, argc[1]);
	map.img.mlx_ptr = mlx_init();
	map.img.win_ptr = mlx_new_window(map.img.mlx_ptr, WIDTH, HEIGHT, "FDF");
	map.img.img = mlx_new_image(map.img.mlx_ptr, WIDTH, HEIGHT);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, \
			&map.img.line_length, &map.img.endian);
	render(&map.img, &map);
	initialize_hooks(&map);
	mlx_hook(map.img.win_ptr, KEY_PRESS, 0, close_window, &map);
	mlx_hook(map.img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_hook(map.img.win_ptr, KEY_PRESS, 0, move, &map);
	mlx_put_image_to_window(map.img.mlx_ptr, map.img.win_ptr, map.img.img, \
			0, 0);
	mlx_loop(map.img.mlx_ptr);
}

void initialize_hooks(t_map *map)
{
	mlx_hook(map->img.win_ptr, KEY_PRESS, 0, close_window, &map);
	mlx_hook(map->img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_hook(map->img.win_ptr, KEY_PRESS, 0, move, &map);
}
