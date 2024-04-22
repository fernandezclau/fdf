/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:23:00 by claferna          #+#    #+#             */
/*   Updated: 2024/04/22 20:40:42 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'destroy_and_render' function destroys an img, creates a new one
** and renders.
*/
void	destroy_and_render(t_map *map)
{
	mlx_destroy_image(map->img.mlx_ptr, map->img.img);
	map->img.img = mlx_new_image(map->img.mlx_ptr, WIDTH, HEIGHT);
	render(&map->img, map);
	mlx_put_image_to_window(map->img.mlx_ptr, map->img.win_ptr, \
			map->img.img, 1, 1);
}

/*
** DESC: The 'my_mlx_pixel_put' functions optimises the representation of bytes.
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}
