/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:32:01 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 18:34:06 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
void	print_square(int x, int y)
{
	//print line
	for (int i = 0; i < 50; i++)
	{
		my_mlx_pixel_put(&img, (x + i), y, 0x00FF0000);
		my_mlx_pixel_put(&img, (x + i), y, 0x00FF0000);
	}
	//print borders
	for (int j = 0; j < 50; j++)
	{
		my_mlx_pixel_put(&img, x, (y + j), 0x00FF0000);
		my_mlx_pixel_put(&img, x, (y + j), 0x00FF0000);
	}
}*/
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	
	/*img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);*/
	mlx_loop(mlx);
}

