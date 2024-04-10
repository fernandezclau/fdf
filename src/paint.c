/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:42:48 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 18:34:48 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESCRIPTION: Gets the max value from two numbers
*/
int	get_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
** DESCRIPTION: Join two dots in the map
*/
void	join_dots(int a_x, int a_y, int b_x, int b_y, t_data *img)
{
	int	x_diff;
	int	y_diff;
	int	max;

	x_diff = b_x - a_x; 			//Difference between Xs
	y_diff = b_y - a_y; 			//Difference between Ys
	max = get_max(x_diff, y_diff);
	x_diff /= max;
	y_diff /= max;
	//----escalar---
	a_x *= 20;
	b_x *= 20;
	a_y *= 20;
	b_y *= 20;
	while (b_x - a_x || b_y - a_y)
	{
		my_mlx_pixel_put(img, a_x, a_y, 0x00FF0000);
		a_x += x_diff;
		a_y += y_diff;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	join_dots(2, 3, 6, 7, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
