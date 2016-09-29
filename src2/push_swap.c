/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:02:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/29 18:04:28 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int			check_piles(t_data *pilea, t_data *pileb, t_data **last_b)
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
		while (tmp->next)
			tmp = tmp->next;
		*last_b = tmp;
		if (i == 3)
			return (0);
		else if (i == 1)
			return (3);
		else if (i == 2)
			return (4);
	}
	return (5);
}

int			check_lista_order(t_data *pil, t_data **last)
{
	t_data		*pilea;

	pilea = pil;
	while (pilea && pilea->next)
	{
		if (pilea->nb < pilea->next->nb)
			pilea = pilea->next;
		else
			return (1);
	}
	*last = pilea;
	return (0);
}

int			check_listb_order(t_data *pil, t_data **last)
{
	t_data		*pilea;

	pilea = pil;
	while (pilea && pilea->next)
	{
		if (pilea->nb > pilea->next->nb)
			pilea = pilea->next;
		else
			return (1);
	}
	*last = pilea;
	return (0);
}

int			move_nb(t_data **pilea, t_data **pileb, t_data *last)
{
	int				ret_pila;
	int				ret_pilb;
	static t_data	*last_b;

	ret_pila = -1;
	ret_pilb = -1;
	if (*pilea)
		ret_pila = check_lista_order(*pilea, &last);
	if (*pileb)
		ret_pilb = check_listb_order(*pileb, &last_b);
	if (!ret_pila && !ret_pilb)
		ft_putendl("A croissant, B decroissant");
	if (!ret_pila && ret_pilb == -1)
		return (1);
	else if (ret_pila == -1)
		ft_putendl("A vide");
	else if (ret_pilb == -1)
		ft_putendl("B vide");
	else if (!ret_pila && ret_pilb == 1)
		ft_putendl("A croissant, B mal trie");
	else if (!ret_pilb && ret_pila == 1)
		ft_putendl("A mal trie, B decroissant");
	else if (ret_pila == 1 && ret_pilb == 1)
		ft_putendl("A et B mal trie");
	if (!ret_pila && !ret_pilb)
		do_pa(pilea, pileb);
	else if (*pilea && *pileb && (*pilea)->next && (*pileb)->next && (*pilea)->nb > \
	(*pilea)->next->nb && (*pileb)->nb < (*pileb)->next->nb)
		do_ss(*pilea, *pileb);
	else if (*pileb && (*pileb)->next && (*pileb)->nb < (*pileb)->next->nb)
		do_sb(*pileb);
	else if (*pilea && (*pilea)->next && last && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->next->nb > last->nb)
	{
		do_sa(*pilea);
		do_ra(pilea);
	}
	else if (last_b && *pileb && last_b->nb > (*pileb)->nb)
		do_rb(pileb);
	else if (*pilea && (*pilea)->next && (*pilea)->nb > (*pilea)->next->nb)
		do_sa(*pilea);
	else if (ret_pila && ret_pilb && *pileb && (*pileb)->nb < (*pilea)->nb)
		do_pa(pilea, pileb);

	else if (ret_pila == 1 && *pilea && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < last->nb)
		do_pb(pilea, pileb);
	else if (ret_pila == 1 && ret_pilb == 1 && *pilea && *pileb && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < last->nb && (*pilea)->nb > (*pileb)->nb)
		do_pb(pilea, pileb);
//	else if ((*pilea && *pileb && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb && (*pilea)->nb < (*pileb)->nb) || (*pilea && (*pilea)->next && (*pilea)->nb < (*pilea)->next->nb))
	else if (pileb && last->nb < (*pilea)->nb && last->nb > (*pileb)->nb)
		do_rra(pilea);
	else if (last && *pilea && last->nb < (*pilea)->nb)
		do_ra(pilea);
	sleep(1);
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
