/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:23:31 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 16:36:05 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>		//READ FILES
# include <stdlib.h>	//MALLOC
# include <stdio.h>		//PRINTF
# include <unistd.h>	//OPEN, CLOSE FILES

# include "minilibx/mlx.h"	//minilbx
# include "libft.h"			//libft
# include "get_next_line.h"	//get_next_line

//INFO: cc main.c -o mi_programa -L./minilibx -lmlx -framework OpenGL -framework AppKit

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

}				t_map;
#endif
