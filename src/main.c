/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/20 15:01:13 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argv, char **argc)
{
	t_data	img;
	t_map	map;
	
	if (argv !=2)
		return (manage_error("Please, enter a map :)\n"));
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 1280, 920, "FDF");
	img.img = mlx_new_image(img.mlx_ptr, 1280, 920);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	initialize_matrix(&map, argc[1]);
	render(&img, &map);
	mlx_hook(img.win_ptr, KEY_PRESS, 0, close_window, NULL);
	mlx_hook(img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_loop(img.mlx_ptr);
}
