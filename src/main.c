/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 13:49:41 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(char **av, int ac, long *pilea)
{
	(void)av;
	char	*str;

	if (check_double(ac, pilea))
		return ;
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

int			main(int ac, char **av)
{
	long	*nb;

	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(av, nb)))
		call_fctn(av, ac, nb);
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
