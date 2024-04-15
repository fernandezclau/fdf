/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/15 18:57:37 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
int	closing(int keycode, t_vars *vars)
{
	//printf("%d%p", keycode, vars);
   	if (keycode == 27)	
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(int argv, char **argc)
{
	t_vars	vars;
	t_data	img;
	//t_map	map;

	//arg control
	if (argv != 2)
		return (manage_error("Se ha producido error en la entrada"));
	printf("%s", argc[0]);
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
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, closing, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_loop(vars.mlx);
}

