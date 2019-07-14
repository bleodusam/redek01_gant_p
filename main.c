/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reporche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:53:45 by reporche          #+#    #+#             */
/*   Updated: 2019/07/13 18:16:54 by reporche         ###   ########.fr       */
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
int		**malloc_a_tab(int p);

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
	if((arg_p = malloc(sizeof(int*) * p)) == NULL)
	 return(NULL);
	 while (i < p)
 	{
 		arg[i] = NULL;
   	if((arg[i] = malloc(sizeof(int) * p)) == NULL)
   		return(NULL);
	}
	return (arg_p);
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
	p = 4; //to be removed when ok

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	/*  ^ = si nb d'argument incorrect : error */

	arg = malloc_a_tab(p);

	while (i < 4)
	{
		while (j < 4)
		{
			if (argv[1][k] != ' ' && (argv[1][k] <= '0' || argv[1][k] >= '9'))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			if (argv[1][k] >= '0' && argv[1][k] <= '9')
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

	my_rush(arg, p);


/*  ^  transfert argv[1] dans arg (plus convertion en int) */
	return (0);
}
