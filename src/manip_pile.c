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


//void		do_pb(t_data *dta, t_datb *dtb)
//{
//}
