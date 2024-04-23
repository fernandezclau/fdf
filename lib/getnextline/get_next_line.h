/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:38:14 by claferna          #+#    #+#             */
/*   Updated: 2024/04/16 20:29:30 by claferna         ###   ########.fr       */
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
<<<<<<< Updated upstream
char		*get_next_line(int fd);
int			ft_read(t_list_g **list, int fd);
char		*ft_get_line(t_list_g *list);
void		ft_clean_list(t_list_g **list);
/*UTILS FUNCTIONS*/
void		ft_extract_line_lst(t_list_g *list, char *line);
void		ft_erase_elements(t_list_g **list, t_list_g *clean_node, \
		char *next_line);
int			ft_find_line(t_list_g *lst);
void		ft_lstadd_line(t_list_g **list, char *buffer);
t_list_g	*ft_lstlast_item(t_list_g *list);
int			ft_get_len_line(t_list_g *list);
=======
int		get_next_line(int fd, char **line);
int		get_line(int fd, char **line);
char		*set_malloc(char **line, char *buffer);
int		add_line(char **line, char *buffer);
>>>>>>> Stashed changes
#endif
