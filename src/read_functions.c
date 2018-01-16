/*
** EPITECH PROJECT, 2017
** read_functions.c
** File description:
** read functions
*/

#include "bsq.h"

int	find_size(int fd)
{
	char	buff[2];
	int	size = 0;

	while (read(fd, buff, 1) && ('0' <= buff[0] && buff[0] <= '9')) {
		size += buff[0] - 48;
		size *= 10;
		buff[1] = '\0';
	}
	return (size / 10);
}

char	*fill_line(char *buff, int len, char *src)
{
	char	*line = malloc(sizeof(char) * (len + 1));
	int	i = 0;

	if (line == NULL)
		return (NULL);
	if (src == NULL) {
		line[0] = buff[0];
		line[1] = '\0';
		return (line);
	}
	while (src[i]) {
		line[i] = src[i];
		i++;
	}
	free(src);
	line[i] = buff[0];
	line[i + 1] = '\0';
	return (line);
}

char	*first_line(int fd)
{
	char	buff[2];
	char	*line = NULL;
	int	len = 0;

	while (read(fd, buff, 1) && buff[0] != '\n') {
		len++;
		line = fill_line(buff, len, line);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*read_line(int fd, int size)
{
	char	trash[2];
	char	*buff;

	buff = malloc(sizeof(char) * (size + 1));
	if (buff == NULL)
		return (NULL);
	read(fd, buff, size);
	buff[size] = '\0';
	read(fd, trash, 1);
	return (buff);
}
