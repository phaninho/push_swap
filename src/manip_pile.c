/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:57:55 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/15 16:34:37 by stmartin         ###   ########.fr       */
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
	newelem = NULL;
	if (!*pileb && *pilea)
	{
		ft_putendl("pileb == NULL pas dta////////////////");
		newelem = list_newnode((*pilea)->nb);
		*pileb = newelem;
		*pilea = (*pilea)->next;
	}
	else if (*pilea && *pileb)
	{
		ft_putendl("milieu////////////");
		newelem = list_newnode((*pilea)->nb);
		newelem->next = tmp;
		*pileb = newelem;
		*pilea = (*pilea)->next;
	}
	else
		ft_putendl("pile a vide, rien n a ete fait");
}

void		do_pa(t_data **pilea, t_data **pileb)
{
	t_data		*newelem;
	t_data		*tmp;

	tmp = *pilea;
	newelem = NULL;
	if (!*pilea && *pileb)
	{
		ft_putendl("pilea == NULL pas dta////////////////");
		newelem = list_newnode((*pileb)->nb);
		*pilea = newelem;
		*pileb = (*pileb)->next;
	}
	else if (*pilea && *pileb)
	{
		ft_putendl("milieu////////////");
		newelem = list_newnode((*pileb)->nb);
		newelem->next = tmp;
		*pilea = newelem;
		*pileb = (*pileb)->next;
	}
	else
		ft_putendl("pile a vide, rien n a ete fait");
}
