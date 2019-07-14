/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:47:07 by tin               #+#    #+#             */
/*   Updated: 2019/07/14 10:47:10 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* Fonction appelée quand on crée le tableau, pr verifier qu'il n'y a pas deux
   fois le meme chiffre dans une colonne / ligne  */

int	check_case(int **tab, int value, int x, int y, int p)
{
	int i;
	int j;

	i = 0;
	while (i < p) //verif de la ligne
	{
		if (tab[i][y] == value && i != x)
		{
			return (-1);  // Un doublon sur la ligne
		}
		i++;
	}
	j = 0;
	while (j < p) // Un dublon sur la colonne
	{
		if (tab[x][j] == value && j != y)
			return (-1);
		j++;
	}
	return (1); //on a checké colonne et ligne => c'est ok
}

/* Les 4 fonctions qui verifient si les conditions d'input sont ok
   => on appelle ces fct une fois que tout le tableau a été rempli */

int	check_up(int **arg, int **tab, int p)
{
	int count;
	int max_found;
	int i;
	int j;

	j = 0;
	while (j < p)
	{
		max_found = 0;
		count = 0;
		i = 0;
		while (i < p)
		{
			if (max_found < tab[i][j])
			{
				max_found = tab[i][j];
				count++;
			}
			i++;
		}
		if (count != arg[0][j])
			return (0);
		j++;
	}
	return (1);
}

int	check_down(int **arg, int **tab, int p)
{
	int count;
	int max_found;
	int i;
	int j;

	j = 0;
	while (j < p)
	{
		max_found = 0;
		count = 0;
		i = p - 1;
		while (i >= 0)
		{
			if (max_found < tab[i][j])
			{
				max_found = tab[i][j];
				count++;
			}
			i--;
		}
		if (count != arg[1][j])
			return (0);
		j++;
	}
	return (1);
}

int	check_left(int **arg, int **tab, int p)
{
	int count;
	int max_found;
	int i;
	int j;

	i = 0;
	while (i < p)
	{
		max_found = 0;
		count = 0;
		j = 0;
		while (j < p)
		{
			if (max_found < tab[i][j])
			{
				max_found = tab[i][j];
				count++;
			}
			j++;
		}
		if (count != arg[2][i])
			return (0);
		i++;
	}
	return (1);
}

int	check_right(int **arg, int **tab)
{
	int count;
	int max_found;
	int i;
	int j;

	i = 0;
	while (i < p)
	{
		max_found = 0;
		count = 0;
		j = p - 1;
		while (j >= 0)
		{
			if (max_found < tab[i][j])
			{
				max_found = tab[i][j];
				count++;
			}
			j--;
		}
		if (count != arg[3][i])
			return (0);
		i++;
	}
	return (1);
}
