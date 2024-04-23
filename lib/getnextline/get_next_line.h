/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:38:14 by claferna          #+#    #+#             */
/*   Updated: 2024/04/23 16:44:33 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*DEFAULT BUFFER_SIZE DECLARATION*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>	//READ LIB
# include <stddef.h>	//SIZE_T LIB
# include <stdlib.h>	//MALLOC, FREE LIB
# include <fcntl.h>		//OPEN, CLOSE LIB

/*MAIN FUNCTION*/
int		get_next_line(int fd, char **line);
int		get_line(int fd, char **line);
char		*set_malloc(char **line, char *buffer);
int		add_line(char **line, char *buffer);
#endif
