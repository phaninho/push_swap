/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 11:19:27 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/15 15:04:58 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data		*list_newnode(int nb)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void		list_addend(t_data *new, t_data **full_list)
{
	t_data	*tmp;

	if (!*full_list && !new)
		return ;
	if (!*full_list && new)
		*full_list = new;
	else
	{
		tmp = *full_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
