/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/17 16:47:04 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argv, char **argc)
{
	t_vars	vars;
	t_data	img;
	t_map	map;

	if (argv != 2)
		return (manage_error("Se ha producido error en la entrada"));
	//window & img initialization
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "FDF");
	img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	//matrix initialization, map processing
	initialize_matrix(&map, argc[1]);
	//rendering matrix
	render(&img, &map);
	//Putting img to window
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//Hooks
	mlx_hook(img.win_ptr, KEY_PRESS, 0, close_window, NULL);
	mlx_hook(img.win_ptr, DESTROY_NOTIFY, 0, close_window_x, NULL);
	mlx_loop(vars.mlx);
}
