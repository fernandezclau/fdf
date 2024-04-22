/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:23:31 by claferna          #+#    #+#             */
/*   Updated: 2024/04/22 20:58:27 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ---- LIBS ----
# include <fcntl.h>     //READ FILES
# include <stdlib.h>    //MALLOC
# include <stdio.h>     //PRINTF
# include <unistd.h>    //OPEN, CLOSE FILES
# include <math.h>      //MATH LIB

// ---- MY LIBS ----
# include "../lib/minilibx/mlx.h"				//minilbx
# include "../lib/libft/libft.h"				//libft
# include "../lib/getnextline/get_next_line.h"	//get_next_line
# include "../lib/printf/ft_printf.h"			//printf

// ---- WINDOWS KEYS ----
# define KEY_PRESS       	2   //key pressing
# define DESTROY_NOTIFY  	17  //close button
# define ESC_KEY         	53  //esc key
# define CONFIGURE_NOTIFY 	22 //Resizing
# define PLUS_KEY			69	//'+'
# define MINUS_KEY			78	// '-'
# define W_KEY				13	//w
# define A_KEY				0	//a
# define S_KEY				1	//S
# define D_KEY				2	//D
// ------ WINDOW SIZING ----
# define HEIGHT	1080
# define WIDTH	1920
// ------ ISOMETRIC ----
# define ANGLE 0.32344

/*
** DESC: The 't_data' struct is due to optimisation purpouses.
*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

/*
** DESC: The 't_map' struct contains info about a map. 
*/
typedef struct s_map
{
	int		width;
	int		height;
	int		**matrix;
	char	*filename;
	int		zoom;
	int		move_x;
	int		move_y;
	t_data	img;
}				t_map;

/*
** DESC: The 't_coords' struct contains the coordinates (x, y).
*/
typedef struct s_coords
{
	int		x;
	int		y;
	float	x_scaled;
	float	y_scaled;
	int		color;
}				t_coords;

// ------- COORDS -------
void	initialize_coords(t_coords *coords, int _x, int _y, int dis);
void	scale_coords(t_coords *a, t_coords *b, int scale);
void	coords_to_isometric(t_coords *a, t_coords *b, t_map *map);
// ------- RENDER --------
void	render(t_data *img, t_map *map);
void	join_dots(t_coords *a, t_coords *b, t_map *map, t_data *img);
// ------- MATRIX -------
int		get_matrix_width(char *file_name);
int		get_matrix_height(char *file_name);
void	fill_matrix(t_map *map);
void	initialize_matrix(t_map *map, char *filename);
// -------- UTILS -------- 
float	get_max(float num1, float num2);
int		manage_error(char *message);
void	process_line(char *line, int *z_matrix);
int		select_color(t_coords *a, t_coords *b, t_map *map);
// -------- IMG -------
void	destroy_and_render(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// ------- HOOKS -----
void	initialize_hooks(t_map *map);
int		close_window(int keycode, t_map *map);
int		close_window_x(void);
int		move(int keycode, t_map *map);
#endif
