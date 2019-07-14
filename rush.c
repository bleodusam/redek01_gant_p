/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:50:15 by tin               #+#    #+#             */
/*   Updated: 2019/07/14 12:34:59 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define GO_NEXT 1
#define GO_BACK -1

void	ft_putchar(char c);
void	print(int **tab, int p);
int		check_case(int **tab, int value, int x, int y, int p);
int		check_up(int **arg, int **tab, int p);
int		check_down(int **arg, int **tab, int p);
int		check_right(int **arg, int **tab, int p);
int		check_left(int **arg, int **tab, int p);
int		**create_null_tab(void);
int		check_if_ok(int **arg, int **tab, int p);
int		**tab_solved(int **tab, int i, int j, int fw_bw, int p);
void	my_rush(int **arg, int p);
int		**create_initial_tab( int p);

int		check_if_ok(int **arg, int **tab, int p)
{
	if (!check_up(arg, tab, p))
		return (0);
	if (!check_down(arg, tab, p))
		return (0);
	if (!check_left(arg, tab, p))
		return (0);
	if (!check_right(arg, tab, p))
		return (0);
	return (1);
}

/* Fonction de backtracking qui remplit le tableau
** en verifiant uniquement qu'il n'y a qu'une seule
** fois chaque chiffre par colonne/ligne */

int		**tab_solved(int **tab, int i, int j, int fw_bw, int p)
{
	while (i >= 0 && i < p)
	{
		while (j >= 0 && j < p)
		{
			while (tab[i][j] < p)
			{
				tab[i][j] = tab[i][j] + 1;
				fw_bw = check_case(tab, tab[i][j], i, j);
				if (fw_bw == 1) // Cas ou la valeur de tab[i][j] est bonne
					break ;
			}
			if (tab[i][j] >= p && fw_bw != GO_NEXT)
				tab[i][j] = 0;
			if (tab[0][0] == 0)
				return (tab);         //cas ou on est revenu tout au debut, aucune solution trouvée
			j = j + fw_bw;  // ca donne soit j++ pr avancer, soit  j-- pr reculer
		}
		if (fw_bw == GO_NEXT) // on avance => passe à la ligne suiv, case 0
			j = 0;
		if (fw_bw == GO_BACK) // on recule => passe à la ligne suiv, case 3
			j = p -1;
		i = i + fw_bw;  // ca donne soit i++ pr avancer, soit  i-- pr reculer
	}
	return (tab);
}

void	my_rush(int **arg)
{
	int **tab;
	int check_ok;

	tab = create_initial_tab();
	while (!check_if_ok(arg, tab) || tab[0][0] == 0)
	{
		if (tab[0][0] == 0) // cas ou on a tout testé, on est revenu à la
		{										// case [0][0] > 4 => donc il n'y a pas de solution
			write(1, "Error\n", 9);
			return ;
		}
		tab = tab_solved(tab, p - 1, p - 1, -1, p);  // nouveau tableau
	}
	print(tab);  // On sort de la boucle pq check_ok = 1 => print le tableau
}
