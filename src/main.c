/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/20 17:58:16 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(t_data *pilea, t_data *pileb, long *nb)
{
	char			*str;
//	t_data			*tmp;
//	t_data			*tmp2;

	if (check_double(pilea->lima, nb))
		return ;
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
//	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n')
		{
			check_nb_order(pilea, pileb);
			break;
		}
		else if (check_instruction(str, &pilea, &pileb))
		{
			ft_putendl_fd("Error", 2);
			break;
		}
/*		tmp = pilea;
		tmp2 = pileb;
		ft_putendl("A   B");
		while (tmp || tmp2)
		{
			if (tmp)
			{
				ft_putnbr(tmp->nb);
				tmp = tmp->next;
			}
			else
				ft_putchar(' ');
			ft_putchar(' ');
			if (tmp2)
			{
				ft_putnbr(tmp2->nb);
				tmp2 = tmp2->next;
			}
			ft_putchar('\n');
		}*/
	}
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	*pilea;
	static t_data	*pileb;

	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(ac == 2 ? ft_strsplit(av[1], ' ') : av, nb, &pilea, ac == 2 ? 0 : 1)))
	{
		pilea->lima = ac - 1;
		call_fctn(pilea, pileb, nb);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
