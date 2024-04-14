/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/14 17:52:58 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argv, char **argc)
{
	t_vars	vars;
	t_data	img;
	t_map	map;

	//arg control
	if (argc != 2)
		return (manage_error("Se ha producido error en la entrada"));
	//window & img initialization
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//matrix initialization, map processing
	//initialize_matrix(&map, filename);
	//rendering matrix
	//render();
	//manage key inputs
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

