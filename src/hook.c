/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:08:51 by claferna          #+#    #+#             */
/*   Updated: 2024/04/23 19:22:39 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** DESC: The 'close_window_x' function exits the program with the 'x' function.
*/
int	close_window_x(t_map *map)
{
	exit(0);
	printf("%d", map->width);
	return (0);
}

/*
** DESC: The 'move' function allows to move the figure around the map.
*/
int	move(int keycode, t_map *map)
{
	if (keycode == PLUS_KEY)
	{
		if (map->zoom < 24)
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
	else if (keycode == ESC_KEY)
		exit(0);
	destroy_and_render(map);
	return (0);
}
