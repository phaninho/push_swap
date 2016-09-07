/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 19:13:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(int lima, int *pilea)
{
	if (lima > 2)
		ft_swap(&pilea[0], &pilea[1]);
}

void		do_sb(int limb, int *pileb)
{
	if (limb > 2)
		ft_swap(&pileb[0], &pileb[1]);
}

void		do_ss(t_data dt)
{
	do_sa(dt.lima, dt.pilea);
	do_sb(dt.limb, dt.pileb);
}

/*
void		do_pb(t_data dt)
{
	if (dt.lima > 0)
	{
		
	}
}*/
