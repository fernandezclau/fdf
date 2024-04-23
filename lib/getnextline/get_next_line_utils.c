#include "get_next_line.h"

char	*set_malloc(char **line, char *buffer)
{
	char		*new;
	int		len_line;
	int		len_buffer;

	len_line = 0;
	while (*line && (*line)[len_line] && (*line)[len_line] != '\n')
		len_line++;
	len_buffer = 0;
	while (buffer[len_buffer] && buffer[len_buffer] != '\n')
		len_buffer++;
	new = (char *)malloc(sizeof(char) * (len_buffer + len_line + 1));
	if (!new)
		return (NULL);
	return (new);
}

int	add_line(char **line, char *buffer)
{
	char		*aux;
	int		i;
	int		j;

	aux = set_malloc(line, buffer);
	if (!aux)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		aux[i++] = (*line)[j++];
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		aux[i++] = buffer[j++];
	aux[i] = buffer[j];
	free(*line);
	*line = aux;
	i = 0;
	while (buffer[j])
		buffer[i++] = buffer[++j];
	buffer[i] = '\0';
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}
