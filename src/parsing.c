/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:42:10 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/09 16:54:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_instruction(char *str, t_data *dta, t_datb *dtb)
{
	if (ft_strlen(str) > 4)
	{
		ft_putendl("Error");
		return (1);
	}
	else if (!(ft_strcmp(str, "sa\n")))
		do_sa(dta);
	else if (!(ft_strcmp(str, "sb\n")))
		do_sb(dtb);
	else if (!(ft_strcmp(str, "ss\n")))
		do_ss(dta, dtb);
	else if (!(ft_strcmp(str, "pa\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "pb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "ra\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rr\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rra\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rrb\n")))
		ft_putendl("entree correct");
	else if (!(ft_strcmp(str, "rrr\n")))
		ft_putendl("entree correct");
	else
	{
		ft_putstr_fd("Error, mauvais entree\n", 2);
		return (1);
	}
	return (0);
}

int			check_double(int lim, long *nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < lim)
	{
		j = i + 1;
		while (j < lim)
		{
			if (nb[i] == nb[j])
			{
				ft_putendl("Error, doublons detected");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_data		*list_newnode(int nb)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->pilea = nb;
	new->next = NULL;
	return (new);
}

void		list_addend(t_data *new, t_data **full_list)
{
	t_data	*tmp;

	if (!*full_list && !new) // leprobleme viens dici
	{
		ft_putstr("tout vide\n");
		return ;
	}
	if (!*full_list && new)
	{
//		ft_putnbr(new->pilea);
		ft_putstr("full_list vide\n");
		*full_list = new;
		ft_putnbr((*full_list)->pilea);
		ft_putstr("\n");
	}
	else
	{
		tmp = *full_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	//	ft_putstr("parcour chaine\n");
	//	ft_putnbr((*full_list)->pilea);
	}
}

int			check_av(char **av, long *nb, t_data **dta)
{
	int		x;
	int		y;
	int		lim;
	t_data	*newelem;

	x = 1;
	if (av && av[x])
	{
		while (av && av[x])
		{
			y = 0;
			while (av[x][y] || av[x][y] != ' ' || av[x][y] != '\n')
			{
				if (ft_isdigit(av[x][y]) || (av[x][y] == '-' && ft_isdigit(av[x][y + 1])))
				{
					y++;
					if (av[x][y] == '\0')
						break;
				}
				else
				{
					ft_putendl("Error, not digit detected");
					return (1);
				}
			}
			nb[x - 1] = ft_atol(av[x]);
			if (nb[x - 1] < INT_MIN || nb[x - 1] > INT_MAX)
			{
				ft_putendl("Error, int overflow");
				return (1);
			}
			x++;
		}
		lim = x - 1;
		x = 0;
		while (x < lim)
		{
			newelem = list_newnode(nb[x]);
			list_addend(newelem, dta);
			x++;
		}
		return (0);
	}
	else
		ft_putendl("Error");
	return (1);
}
