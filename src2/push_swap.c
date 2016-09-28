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

int			check_piles(t_data *pilea, t_data *pileb)
{
	t_data		*tmp;
	int			i;

	if (!pilea)
		return (1);
	if (!pileb)
		return (2);
	if (pilea && pileb)
	{
		tmp = pilea;
		while (tmp && tmp->next)
		{
			if (tmp->nb < tmp->next->nb)
				tmp = tmp->next;
			else
				break;
			if (!tmp)
				i = 1;
		}
		tmp = pileb;
		while (tmp && tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
				tmp = tmp->next;
			else
				break;
			if (!tmp)
				i = i + 2;
		}
		if (i == 3)
			return (0);
		else if (i == 1)
			return (3);
		else if (i == 2)
			return (4);
	}
	return (5);
}

int			check_list_order(t_data *pila, t_data *pileb)
{
	t_data		*pilea;

	pilea = pila;
	if (pileb)
		return(1);
	while (pilea && pilea->next)
	{
		if (pilea->nb < pilea->next->nb)
			pilea = pilea->next;
		else
			return (1);
	}
	return (0);
}

int			move_nb(t_data **pilea, t_data **pileb, t_data *last)
{
	int			ret_piles;

	if (!check_list_order(*pilea, *pileb))
		return (1);
	if (*pilea || *pileb)
		ret_piles = check_piles(*pilea, *pileb);
	if (!ret_piles)
		ft_putendl("A croissant, B decroissant");
	else if (ret_piles == 1)
		ft_putendl("A vide");
	else if (ret_piles == 2)
		ft_putendl("B vide");
	else if (ret_piles == 3)
		ft_putendl("A croissant, B mal trie");
	else if (ret_piles == 4)
		ft_putendl("A mal trie, B decroissant");
	else if (ret_piles == 5)
		ft_putendl("A et B mal trie");
	if (*pilea && (*pilea)->next && (*pilea)->nb > (*pilea)->next->nb)
		do_sa(*pilea);
	else if (*pilea && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb)
		do_pb(pilea, pileb);
	else if (pileb && last->nb < (*pilea)->nb && last->nb > (*pileb)->nb)
		do_rra(pilea);
	else if (last->nb < (*pilea)->nb)
		do_ra(pilea);
	return (0);
}

void		push_swap(t_data *pilea, t_data *pileb)
{
	t_data		*tmp;
	t_data		*last;
	int			mv_ret;

	mv_ret = 0;
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
	while (!mv_ret)
	{
		mv_ret = move_nb(&pilea, &pileb, last);
		if (mv_ret == 1)
			ft_putendl("OK");
		else if (mv_ret == 2)
			ft_putendl("KO");
	}
	tmp = pilea;
		ft_putendl("pile A apres traitement :");
	while (pilea)
	{
		ft_putnbr(pilea->nb);
		ft_putchar('\n');
		pilea = pilea->next;
	}
}
