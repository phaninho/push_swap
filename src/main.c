/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/09 16:45:19 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		call_fctn(char **av, t_data *dta, t_datb *dtb, long *nb)
{
	(void)av;
	char	*str;

		ft_putstr("entre la\n");
	if (check_double(dta->lima, nb))
		ft_putstr("entre la\n");
		return ;
	if (!(str = (char *)malloc(sizeof(char) * 5)))
		return ;
	str[4] = '\0';
	ft_putendl("entrer une instruction");
	while (fgets(str, sizeof str, stdin))
	{
		if (str[0] == '\n' || check_instruction(str, dta, dtb))
			break;
	}
	ft_putstr("sortie du fgets\n");
}

int			main(int ac, char **av)
{
	long			*nb;
	static t_data	*dta;
	static t_datb	*dtb;

//	dta = (t_data *)malloc(sizeof(t_data));
//	dtb = (t_datb *)malloc(sizeof(t_datb));
	nb = (long *)malloc(sizeof(long) * (ac - 1));
	if (ac > 1 && (!check_av(av, nb, dta)))
	{
		ft_putstr("entre ici\n");
		ft_putnbr(dta->pilea);
		ft_putstr("entre la\n");
		dta->lima = ac - 1;
		call_fctn(av, dta, dtb, nb);
	}
	else
		ft_putendl("Need arguments, please enter numbers seperate by spaces");
	return (0);
}
