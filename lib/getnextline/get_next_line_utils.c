/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:52:33 by claferna          #+#    #+#             */
/*   Updated: 2024/04/10 18:36:41 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* DESC: The 'ft_find_line' finds the '\n' character in BUFFER_SIZE range.*/
int	ft_find_line(t_list_g *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

/* DESC: The 'ft_lstlast' function finds the last element of a list.*/
t_list_g	*ft_lstlast_item(t_list_g *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/* DESC: The 'ft_lstadd_line' adds a new element to a list.*/
void	ft_lstadd_line(t_list_g **list, char *buffer)
{
	t_list_g	*new_node;
	t_list_g	*last_node;

	new_node = (t_list_g *)malloc(sizeof(t_list_g));
	if (!list)
		return ;
	last_node = ft_lstlast_item(*list);
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

/* DESC: The 'ft_get_len_line' gets the length of the current line.*/
int	ft_get_len_line(t_list_g *list)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

/* DESC: The 'ft_extract_line_lst' extracts all the elements of the list 
corresponding to the current line.*/
void	ft_extract_line_lst(t_list_g *list, char *line)
{
	int	i;
	int	k;

	if (!list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				line[k++] = '\n';
				line[k] = '\0';
				return ;
			}
			line[k++] = list->content[i++];
		}
		list = list->next;
	}
	line[k] = '\0';
}
