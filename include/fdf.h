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

# include <fcntl.h>	//READ FILES
# include <stdlib.h>	//MALLOC
# include <stdio.h>	//PRINTF
# include <unistd.h>	//OPEN, CLOSE FILES
# include <math.h>	//MATH LIB

# include "../lib/minilibx/mlx.h"		//minilbx
# include "../lib/libft/libft.h"		//libft
# include "../lib/getnextline/get_next_line.h"	//get_next_line

//INFO: cc main.c -o mi_programa -L./minilibx -lmlx -framework OpenGL -framework AppKit
//-Wall -Wextra -Werror src/process_map.c -o mi_programa -L./lib/minilibx -lmlx -framework OpenGL -framework AppKit lib/libft/libft.a lib/getnextline/getnextline.a
/*
** DESC: The 't_data' struct is due to optimisation purpouses.
*/
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*
** DESC: The 't_map' struct contains info about a map. 
*/
typedef struct	s_map
{
	int		width;
	int		height;
	int		**matrix;

}				t_map;

/*
** DESC: The 't_coords' struct contains the coordinates (x, y).
*/
typedef struct s_coords
{
	float	x;
	float	y;

}				t_coords;

// ------- COORDS -------
void	initialize_coords(t_coords *coords, float _x, float _y);
void	scale_coords(t_coords *a, t_coords *b, int scale);
void	coords_to_isometric(t_coords *a, t_coords *b, int **matrix);
// ------- PAINT --------
void	paint(t_data *img, t_map *map);
void	join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img);
// ------- MATRIX -------
int	get_matrix_width(char *file_name);
int	get_matrix_height(char *file_name);
void	fill_matrix(char *file_name, t_map *map);
// -------- UTILS -------- 
int	get_max(int num1, int num2);
void	process_line(char *file_name, int *z_matrix);
void	clean_line(char *line);
// -------- WINDOW -------
#endif
