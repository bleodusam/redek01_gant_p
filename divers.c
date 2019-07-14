/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:47:48 by tin               #+#    #+#             */
/*   Updated: 2019/07/14 12:35:34 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c);

// imperssion du resultat final

void	print(int **tab, int p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (j < p)
		{
			ft_putchar(tab[i][j] + '0');
			if(j < p - 1)
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**create_initial_tab(int p)
{
	int **tab;
	int i;
	int j;

	tab = NULL;
	tab = malloc(sizeof(int*) * p);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < p)
	{
		tab[i] = NULL;
		tab[i] = malloc(sizeof(int) * p);
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while (j < p)
		{
			tab[i][j] = ((j + i) % p) + 1;
			j++;
		}
		i++;
	}
	return (tab);
}
