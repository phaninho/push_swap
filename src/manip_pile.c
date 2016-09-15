/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/15 15:10:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_sa(t_data *pilea)
{
	if (pilea)
		ft_swap(&pilea->nb, &pilea->next->nb);
}

void		do_sb(t_data *pileb)
{
	if (pileb)
		ft_swap(&pileb->nb, &pileb->next->nb);
}

void		do_ss(t_data *pilea, t_data *pileb)
{
	do_sa(pilea);
	do_sb(pileb);
}

void		do_pb(t_data **pilea, t_data **pileb)
{
	t_data		*newelem;
	t_data		*tmp;

	tmp = *pileb;
	if (*pileb)
	{
		ft_putendl("entre dans le test, pileb n est pas vide");
		ft_putnbr((*pileb)->nb);
	}
	newelem = NULL;
	if (!*pileb && *pilea)
	{
		ft_putendl("pileb == NULL pas dta////////////////");
	//	newelem = list_newnode((*dta)->pilea);
	//	newelem->next = tmp;
	//	*dtb = newelem;;
		*pileb = *pilea;
		*pilea = (*pilea)->next;
	}
	else if (*pilea)
	{
		ft_putendl("milieu////////////");
		newelem = list_newnode((*pilea)->nb);
		newelem->next = tmp;
		*pileb = tmp;
	}
	else
		ft_putendl("pile a vide, rien n a ete fait");
}
