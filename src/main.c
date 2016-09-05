/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/05 16:55:03 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_instruction(char *str)
{
	if (ft_strcmp(str, "sa"))
		ft_putendl("ins Error");
	return (1);
}

void		call_fctn(char **av)
{
	(void)av;
	char	str[5];
//	if (!(str = (char *)malloc(sizeof(char) * 4)))
//		return ;
	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n' || check_instruction(str))
			break;
	}
	ft_putstr("sortie du fgets\n");
}

int			check_av(int ac, char **av)
{
	int		x;
	int		y;
	int		*nb;

	nb = 0;
	x = 1;
	nb = (int *)malloc(sizeof(int) * (ac - 1));
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
			ft_putnbr(nb[x - 1]);
			ft_putchar('\n');
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
	if (ac > 1 && check_av(ac, av))
		call_fctn(av);
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
