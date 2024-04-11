/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:23:31 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 20:29:47 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>		//READ FILES
# include <stdlib.h>	//MALLOC
# include <stdio.h>		//PRINTF
# include <unistd.h>	//OPEN, CLOSE FILES

# include "../lib/minilibx/mlx.h"				//minilbx
# include "../lib/libft/libft.h"				//libft
# include "../lib/getnextline/get_next_line.h"//get_next_line

//INFO: cc main.c -o mi_programa -L./minilibx -lmlx -framework OpenGL -framework AppKit
//-Wall -Wextra -Werror src/process_map.c -o mi_programa -L./lib/minilibx -lmlx -framework OpenGL -framework AppKit lib/libft/libft.a lib/getnextline/getnextline.a
//optimisation purpouses
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//struct that contais map info
typedef struct	s_map
{
	int		width;
	int		height;
	int		**matrix;

}				t_map;

typedef struct s_coords
{
	float	x;
	float	y;

	void initialice(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
}				t_coords;


// -------- MAIN --------

// ------- PAINT --------

// ---- PROCESS MAP -----

// ---- WINDOW UTILS ----

#endif
