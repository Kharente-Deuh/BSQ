/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** compute the length of a string
*/

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i])
			i++;
	return (i);
}
