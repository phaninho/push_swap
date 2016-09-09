/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/09 12:11:55 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(t_data *dta)
{
	ft_swap(&dta->pilea, &dta->next->pilea);
//	if (lima > 2)
//		ft_swap(&pilea[0], &pilea[1]);
}

void		do_sb(t_datb *dtb)
{
	ft_swap(&dtb->pileb, &dtb->next->pileb);

//	if (limb > 2)
//		ft_swap(&pileb[0], &pileb[1]);
}

void		do_ss(t_data *dta, t_datb *dtb)
{
	do_sa(dta);
	do_sb(dtb);
}

/*
void		do_pb(t_data dt)
{
	if (dt.lima > 0)
	{
		
	}
}*/
