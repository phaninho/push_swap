/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 18:53:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(char **av, t_data dt)
{
	(void)av;
	char	*str;

	if (check_double(dt.lima, dt.pilea))
		return ;
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n' || check_instruction(str, dt))
			break;
	}
	ft_putstr("sortie du fgets\n");
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	dt;

	dt.lima = ac - 1;
	nb = (long *)malloc(sizeof(long) * (ac - 1));
	dt.pilea = (int *)malloc(sizeof(int) * (ac - 1));
	dt.pileb = (int *)malloc(sizeof(int) * (ac - 1));
	if (ac > 1 && (!check_av(av, nb, dt.pilea)))
		call_fctn(av, dt);
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
