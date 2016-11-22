/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/22 19:36:01 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(t_data *pilea, t_data *pileb, long *nb)
{
	char			*str;

	if (check_double(pilea->lima, nb))
		return ;
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
	while (fgets(str, sizeof str, stdin))
	{

		if (check_instruction(str, &pilea, &pileb))
		{
			ft_putendl_fd("Error", 2);
			break;
		}
	}
	check_nb_order(pilea, pileb);
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	*pilea;
	static t_data	*pileb;

	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(ac == 2 ? ft_strsplit(av[1], ' ') : av, nb, \
		&pilea, ac == 2 ? 0 : 1)))
	{
		pilea->lima = ac - 1;
		call_fctn(pilea, pileb, nb);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
