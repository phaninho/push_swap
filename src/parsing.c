/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:42:10 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 19:18:09 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_instruction(char *str, t_data dt)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 4)
	{
		ft_putendl("Error");
		return (1);
	}
	else if (!(ft_strcmp(str, "sa\n")))
		do_sa(dt.lima, dt.pilea);
	else if (!(ft_strcmp(str, "sb\n")))
		do_sa(dt.limb, dt.pileb);
	else if (!(ft_strcmp(str, "ss\n")))
		do_ss(dt);
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
		ft_putstr_fd("Error, mauvais entree\n", 2);
		return (1);
	}
	while (dt.pilea && i < dt.lima)
	{
		ft_putendl("pile a :");
		ft_putchar('[');
		ft_putnbr(dt.pilea[i]);
		ft_putchar(']');
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (dt.pileb && i < dt.limb)
	{
		ft_putendl("pile b :");
		ft_putchar('[');
		ft_putnbr(dt.pileb[i]);
		ft_putchar(']');
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int			check_double(int lim, int *pilea)
{
	int		i;
	int		j;

	i = 0;
	while (i < lim)
	{
		j = i + 1;
		while (j < lim)
		{
			if (pilea[i] == pilea[j])
			{
				ft_putendl("Error, doublons detected");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			check_av(char **av, long *nb, int *pilea)
{
	int		x;
	int		y;
	int		lim;
	x = 1;
	if (av && av[x])
	{
		while (av && av[x])
		{
			y = 0;
			while (av[x][y] || av[x][y] != ' ' || av[x][y] != '\n')
			{
				if (ft_isdigit(av[x][y]) || (av[x][y] == '-' && ft_isdigit(av[x][y + 1])))
				{
					y++;
					if (av[x][y] == '\0')
						break;
				}
				else
				{
					ft_putendl("Error, not digit detected");
					return (1);
				}
			}
			nb[x - 1] = ft_atol(av[x]);
			if (nb[x - 1] < INT_MIN || nb[x - 1] > INT_MAX)
			{
				ft_putendl("Error, int overflow");
				return (1);
			}
			x++;
		}
		lim = x;
		x = 0;
		while (x < lim)
		{
			pilea[x] = nb[x];
			x++;
		}
		return (0);
	}
	else
		ft_putendl("Error");
	return (1);
}
