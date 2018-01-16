/*
** EPITECH PROJECT, 2017
** fill_tab.c
** File description:
** fill tab
*/

#include "bsq.h"

int	**fill_tab(char **bsq, int size, int len)
{
	int	**tab;
	int	i = 0;
	int 	j = 0;

	tab = malloc(sizeof(int *) * size);
	if (tab == 0)
		return (NULL);
	while (i < size) {
		j = 0;
		tab[i] = malloc(sizeof(int) * len);
		if (tab[i] == NULL)
			return (NULL);
		while (bsq[i][j]) {
			(bsq[i][j] == '.') ? (tab[i][j] = 0) : (tab[i][j] =
					INT_MAX);
			j++;
		}
		i++;
	}
	return (tab);
}

void	free_tables(char **bsq, int **tab, int size)
{
	int	i = 0;
	int	len = 0;

	while (i < size) {
		len = my_strlen(bsq[i]);
		write(1, bsq[i], len);
		write(1, "\n", 1);
		free(tab[i]);
		free(bsq[i]);
		i++;
	}
	free(tab);
	free(bsq);
}

void	compute_bsq(char **bsq, int **tab, int max, int size)
{
	int	i = find_first_square_i(tab, size, my_strlen(bsq[0]), max);
	int	j = find_first_square_j(tab, size, my_strlen(bsq[0]), max);
	int	x = 0;
	int	y = 0;
	int	tmp = 0;

	tmp = j;
	while (y < max) {
		j = tmp;
		x = 0;
		while (x < max) {
			bsq[i][j] = 'x';
			j--;
			x++;
		}
		i--;
		y++;
	}
	free_tables(bsq, tab, size);
}

int **solve_bsq_2(int **tab, int *ind, int *swap, int *max)
{
	if (tab[ind[0]][ind[1]] != INT_MAX) {
		if (border_verif(tab, ind[0], ind[1]) != 1) {
			tab = other(tab, ind[0], ind[1]);
			if (*max < tab[ind[0]][ind[1]]) {
				*max = tab[ind[0]][ind[1]];
				*swap = 1;
			}
		} else
			tab = border(tab, ind[0], ind[1]);
	}
	return (tab);
}

void	solve_bsq(char **bsq, int size, int len)
{
	int	max = 0;
	int	**tab = fill_tab(bsq, size, len);
	int	ind[2] = { 0, 0 };
	int	swap = 1;

	while (swap == 1) {
		swap = 0;
		ind[0] = 0;
		while (ind[0] < size) {
			ind[1] = 0;
			while (ind[1] < len) {
				solve_bsq_2(tab, ind, &swap, &max);
				ind[1]++;
			}
			ind[0]++;
		}
	}
	compute_bsq(bsq, tab, max, size);
}
