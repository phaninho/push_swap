/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:02:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/20 19:17:26 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void		move_nb(t_data *pilea, t_data *pileb)
{
	(void)pilea;
	(void)pileb;

	ft_putstr("entre");
}

void		push_swap(t_data *pilea, t_data *pileb)
{
	t_data		*tmp;

	tmp = pilea;
	while (tmp)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		if (tmp->next && tmp->nb > tmp->next->nb)
		{
			move_nb(pilea, pileb);
			tmp = pilea;
		}
		else
			tmp = tmp->next;
	}
}
