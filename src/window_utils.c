/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:55:29 by claferna          #+#    #+#             */
/*   Updated: 2024/04/16 20:07:17 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'close_window' function exits the program with the 'ESC' key.
*/
int	close_window(int keycode, void *param)
{
	if (keycode == ESC_KEY)
	{
		exit(0);
	}
	printf("%p", param);
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
