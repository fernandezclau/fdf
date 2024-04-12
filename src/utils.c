#include "../include/fdf.h"
/*
** DESC: Gets the max value from two numbers
*/
int	get_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

/*
** DESC: The 'clean_line' cleans the line bad characters?
*/
void	clean_line(char *line)
{
}

/*
** DESC: The 'process_line' process a line pouring it into the matrix.
*/
void	process_line(char *file_name, char  *z_matrix)
{
	char **items;
	int	i;
	
	i = 0;
	items = ft_split(line, ' ');
	while(items[i])
	{
		*z_matrix[i] = ft_atoi(items[i]);
		free(items[i]);
		i++;
	}
}
