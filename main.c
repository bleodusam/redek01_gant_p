/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reporche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:53:45 by reporche          #+#    #+#             */
/*   Updated: 2019/07/14 14:35:32 by reporche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		**malloc_a_tab(int p)
{
	int **arg_p;
	int i;

	i = 0;
	arg_p = NULL;
	if ((arg_p = malloc(sizeof(int*) * p)) == NULL)
		return (NULL);
	while (i < p)
	{
		arg_p[i] = NULL;
		if ((arg_p[i] = malloc(sizeof(int) * p)) == NULL)
			return (NULL);
		i++;
	}
	return (arg_p);
}

int		ft_error(int argc, char **argv, int p)
{
	int i;

	i = 0;
	if (argc != 2) //Si il y a plus de 2 argument : fin du programme
		return (0);
	while (argv[1][i])
		i++;
	if (i != ((2 * (4 * p)) - 1)) //Si l'argument est trop court ou long : fin du programme
		return (0);
	//	return (0);
	return (1);
}

int		ft_fup_arg(int **arg, char **argv, int p)
{
	int i;
	int j;
	int k;
	char c;

	i = 0;
	j = 0;
	k = 0;
	while (i < p)
	{
		while (j < p && k < ((2 * (4 * p)) - 1))
		{
			if (!(argv[1][k] == ' ' || (argv[1][k] > '0' && argv[1][k] < ('0' + p + 1)))) //Si il y a autre chose qu'un espace ou qu'un chiffre : fin du programme
				{
					c = argv[1][k];
					write(1, &c, 1);
					return (0);

				}
			if (argv[1][k] > '0' && argv[1][k] < ('0' + p + 1))
			{
				arg[i][j] = argv[1][k] - 48;
				j++;
			}
			k++;
		}
		arg[i][j] = '\0';
		j = 0;
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int **arg;
	int j;
	int i;
	int k;
	int p;

	i = 0;
	j = 0;
	k = 0;
	p = 6; //to be removed when ok
	arg = malloc_a_tab(p);
	if (ft_error(argc, argv, p) == 0) //On check les erreurs, si il y en a : fin du programme
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_fup_arg(arg, argv, p) == 0) //On remplie et converti (en int) arg et si il y a une erreur : fin du programme
	{
		write(1, "Error\n", 6);
		return (0);
	}
	my_rush(arg, p); //Algo de remplissage
	return (0); //Fin du programme
}
