/*
** EPITECH PROJECT, 2017
** main.c
** File description
** bsq main
*/

#include "bsq.h"

char **fill_bsq(int size, char **bsq, int fd, int len)
{
	int	i = 1;

	while (i < size) {
		bsq[i] = read_line(fd, len);
		if (bsq[i] == NULL)
			exit (84);
		if (my_strlen(bsq[i]) != len) {
			exit (84);
		}
		i++;
	}
	return (bsq);
}

char	**init(char *str, int *len, int *size, int *fd)
{
	char	**bsq = NULL;

	*fd = open(str, O_RDONLY);
	if (*fd == -1)
		exit (84);
	*size = find_size(*fd);
	if (*size < 1)
		exit (84);
	bsq = malloc(sizeof(char *) * *size);
	if (bsq == NULL)
		exit (84);
	bsq[0] = first_line(*fd);
	if (bsq == NULL)
		exit (84);
	*len = my_strlen(bsq[0]);
	if (*len < 1)
		exit (84);
	bsq = fill_bsq(*size, bsq, *fd, *len);
	return (bsq);
}

int	main(int ac, char **av)
{
	int	fd = 0;
	int	size = 0;
	char	**bsq = NULL;
	int	len = 0;

	if (ac != 2 || my_strlen(av[1]) == 0)
		return (84);
	bsq = init(av[1], &len, &size, &fd);
	if (check_table(bsq, size) != 0)
		return (84);
	close(fd);
	solve_bsq(bsq, size, len);
	return (0);
}
