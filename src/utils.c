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
** DESC: The 'manage_errors' function prints an error message.
*/
int	manage_error(char *message)
{
	ft_printf("%s", message);
	return (-1);
}

/*
** DESC: The 'process_line' process a line pouring it into the matrix.
*/
void	process_line(char *line, int  *z_matrix)
{
	char	**items;
	int		num;
	int		i;
	
	i = 0;
	items = ft_split(line, ' ');
	if (items)
	{
		while(items[i])
		{
			num = ft_atoi(items[i]);
			z_matrix[i] = num;
			free(items[i]);
			i++;
		}
	}
}
