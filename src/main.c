/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/05 13:25:09 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(char **av)
{
	(void)av;
	ft_putendl("plouf");
}

int			check_av(char **av)
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
				ft_putnbr(x);
				ft_putnbr(y);
				ft_putstr(" arguments [");
				ft_putchar(av[x][y]);
				ft_putstr("]\n");
				if (ft_isdigit(av[x][y]))
				{
					y++;
					if (av[x][y] == '\0')
					{
						ft_putendl("entre");
						break;
					}
				}
				else
				{
					ft_putendl("Error");
					break;
				}
			}
			x++;
		}
		return (1);
	}
	else
	{
		ft_putendl("Error");
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac > 1 && check_av(av))
		call_fctn(av);
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
