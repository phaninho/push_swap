/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:02:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/20 19:04:37 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void				push_swap(t_data *pilea, t_data *pileb)
{
	(void)pileb;
	while (pilea)
	{
		ft_putnbr(pilea->nb);
		ft_putchar('\n');
		pilea = pilea->next;
	}
}
