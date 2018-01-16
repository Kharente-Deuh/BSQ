/*
** EPITECH PROJECT, 2017
** check_table.c
** File description:
** check table
*/

#include "bsq.h"

int	check_table(char **bsq, int size)
{
	int	i = 0;
	int	j = 0;

	while (i < size) {
		j = 0;
		while (bsq[i][j]) {
			if (bsq[i][j] != '.' && bsq[i][j] != 'o')
				return (84);
			j++;
		}
		i++;
	}
	return (0);
}
