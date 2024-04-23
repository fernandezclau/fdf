#include "get_next_line.h"

int	get_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				res;

	*line = NULL;
	res = add_line(line, buffer);
	while (res != -1 && (*line)[res] != '\n')
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 1)
		{
			if (res < 0)
			{
				free(*line);
				*line = NULL;
			}
			return (res);
		}
		buffer[res] = '\0';
		res = add_line(line, buffer);
	}
	if (res == -1)
		return (-1);
	(*line)[res] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	return (get_line(fd, line));
}
/*
#include <stdio.h>
int main(void)
{
	char *file = "file";
	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	char *line;
	get_next_line(fd, &line);
		printf("%s", line);
	//system("leaks -q a.out");
	return (0);
}*/
