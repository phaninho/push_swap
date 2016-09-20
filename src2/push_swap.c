/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:02:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/20 19:41:58 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void		move_nb(t_data **pilea, t_data **pileb)
{
	if (*pilea && (*pilea)->next)
	{
		if ((*pilea)->nb > (*pilea)->next->nb)
			do_sa(*pilea);
	}
	(void)pileb;
}

void		push_swap(t_data *pilea, t_data *pileb)
{
	t_data		*tmp;

	tmp = pilea;
		ft_putendl("liste des nombres :");
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	tmp = pilea;
	while (tmp)
	{
		if (tmp->next && tmp->nb > tmp->next->nb)
		{
			move_nb(&pilea, &pileb);
			tmp = pilea;
		}
		else
			tmp = tmp->next;
	}
	tmp = pilea;
		ft_putendl("apres traitement :");
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
