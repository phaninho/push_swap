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

void		move_nb(t_data **pilea, t_data **pileb, t_data *last)
{
	t_data	*tmp;

	tmp = *pilea;
	while (tmp)
	{
		if (tmp->next && tmp->nb > tmp->next->nb)
			do_sa(tmp);
		else if (tmp->next && tmp->nb > last->nb)
			do_ra(&tmp);
		tmp = tmp->next;
	}
	
	(void)pileb;
}

void		push_swap(t_data *pilea, t_data *pileb)
{
	t_data		*tmp;
	t_data		*last;
	tmp = pilea;
		ft_putendl("liste des nombres :");
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		if (!(tmp->next))
			last = tmp;
		tmp = tmp->next;
	}
	move_nb(&pilea, &pileb, last);
	tmp = pilea;
		ft_putendl("apres traitement :");
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
