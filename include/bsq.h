/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** printf
*/

#ifndef __BSQ_H__
# define __BSQ_H__

#include <limits.h>
#include "my.h"

int	border_verif(int **, int, int);
int	**border(int **, int, int);
int	**other(int **, int, int);
int	find_first_square_i(int **, int, int, int);
int	find_first_square_j(int **, int, int, int);
int	check_table(char **, int);
void	solve_bsq(char **, int, int);
int	find_size(int);
char	*read_line(int, int);
char	*first_line(int);

#endif
