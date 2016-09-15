/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/15 15:59:30 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(char **av, t_data *pilea, t_data *pileb, long *nb)
{
	(void)av;
	char	*str;

	if (check_double(pilea->lima, nb))
		return ;
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n' || check_instruction(str, &pilea, &pileb))
			break;
	}
	ft_putstr("sortie du fgets\n");
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	*pilea;
	static t_data	*pileb;

	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(av, nb, &pilea)))
	{
		pilea->lima = ac - 1;
		call_fctn(av, pilea, pileb, nb);
	}
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
