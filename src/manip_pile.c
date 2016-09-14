/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/14 14:27:12 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(t_data *dta)
{
	ft_swap(&dta->pilea, &dta->next->pilea);
}

void		do_sb(t_datb *dtb)
{
	ft_swap(&dtb->pileb, &dtb->next->pileb);
}

void		do_ss(t_data *dta, t_datb *dtb)
{
	do_sa(dta);
	do_sb(dtb);
}

void		do_pb(t_data *dta, t_datb *dtb)
{
	t_datb		*newelem;
	if (dtb)
	{
		ft_putendl("entre dans le test");
		ft_putnbr(dtb->pileb);
	}
	newelem = NULL;
	if (!dtb && dta)
	{
		ft_putendl("debut////////////////");
		newelem = list_newnodeb(dta->pilea);
		newelem->next = dtb;
		dtb = newelem;
		dta = dta->next;
	}
	else if (dta)
	{
		ft_putendl("milieu////////////");
		newelem = list_newnodeb(dta->pilea);
		newelem->next = dtb;
		dtb = newelem;
	}
	else
		ft_putendl("pile a vide, rien n a ete fait");
}
