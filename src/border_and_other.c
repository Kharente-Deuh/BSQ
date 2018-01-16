 /*
** EPITECH PROJECT, 2017
** border_and_other.c
** File description:
** border and other
*/

#include "bsq.h"

int	border_verif(int **tab, int i, int j)
{
	if (i > 0 && j > 0)
		return (0);
	if (i == 0 && j == 0)
		return (1);
	else if (i > 0 && j == 0) {
		if (tab[i - 1][j] == INT_MAX)
			return (0);
	} else if (i == 0 && j > 0) {
		if  (tab[i][j - 1] != INT_MAX)
			return (1);
	}
	return (1);
}

int	**border(int **tab, int i, int j)
{
	if (i == 0 && j == 0)
		tab[i][j] = 1;
	else if (i > 0 && j == 0)
		tab[i][j] = 1;
	else if (i == 0 && j > 0)
		tab[i][j] = 1;
	return (tab);
}

int 	**other(int **tab, int i, int j)
{
	if (tab[i - 1][j] == INT_MAX || tab[i - 1][j - 1] == INT_MAX ||
			tab[i][j - 1] == INT_MAX) {
		tab[i][j] = 1;
	} else if (tab[i - 1][j] <= tab[i - 1][j - 1] &&
			tab[i - 1][j - 1] <= tab[i][j - 1]) {
		tab[i][j] = tab[i - 1][j] + 1;
	} else if (tab[i - 1][j - 1] <= tab[i - 1][j] &&
			tab[i - 1][j] <= tab[i][j - 1]) {
		tab[i][j] = tab[i - 1][j - 1] + 1;
	} else
		tab[i][j] = tab[i][j - 1] + 1;
	return (tab);
}


int	find_first_square_i(int **tab, int size, int len, int max)
{
	int	i = 0;
	int	j = 0;

	while (i < size) {
		j = 0;
		while (j < len) {
			if (tab[i][j] == max)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	find_first_square_j(int **tab, int size, int len, int max)
{
	int	i = 0;
	int	j = 0;

	while (i < size) {
		j = 0;
		while (j < len) {
			if (tab[i][j] == max)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}
