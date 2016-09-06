/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/06 16:43:25 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_instruction(char *str)
{
	if (ft_strlen(str) > 4)
	{
		ft_putendl("Error");
		return (1);
	}
	else if (!(ft_strcmp(str, "sa\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "sb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "ss\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "pa\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "pb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "ra\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rr\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rra\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rrb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rrr\n")))
		ft_putendl("entree correct");
	else
	{
		ft_putstr("mauvais entree\n");
		return (1);
	}
	return (0);
}

int			check_double(int ac, int *pilea)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			//if (j == i && j + 1 < ac)
			//	j++;
			if (pilea[i] == pilea[j])
			{
				ft_putendl("doublons detected, Error");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		call_fctn(char **av, int ac, int *pilea)
{
	(void)av;
	char	*str;

	if (check_double(ac, pilea))
	{
		ft_putendl("Error");
		return ;
	}
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n' || check_instruction(str))
			break;
	}
	ft_putstr("sortie du fgets\n");
}

int			check_av(char **av, int *nb)
{
	int		x;
	int		y;

	x = 1;
	if (av && av[x])
	{
		while (av && av[x])
		{
			y = 0;
			while (av[x][y] || av[x][y] != ' ' || av[x][y] != '\n')
			{
				if (ft_isdigit(av[x][y]) || av[x][y] == '-')
				{
					y++;
					if (av[x][y] == '\0')
						break;
				}
				else
				{
					ft_putendl("Error");
					break;
				}
			}
			//probleme avec atoi, il transforme les int overflow en int
			nb[x - 1] = ft_atoi(av[x]);
			if (nb[x - 1] < INT_MIN || nb[x - 1] > INT_MAX)
			{
				ft_putendl("Error");
				return (0);
			}
			x++;
		}
		return (1);
	}
	else
		ft_putendl("Error");
	return (0);
}

int			main(int ac, char **av)
{
	int		*nb;

	nb = (int *)malloc(sizeof(int) * (ac - 1));
	if (ac > 1 && check_av(av, nb))
		call_fctn(av, ac, nb);
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
