/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:42:10 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/24 12:14:25 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_instruction(char *str, t_data **pilea, t_data **pileb)
{
	if (ft_strlen(str) > 4)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	else if (!(ft_strcmp(str, "sa\n")))
		do_sa(*pilea);
	else if (!(ft_strcmp(str, "sb\n")))
		do_sb(*pileb);
	else if (!(ft_strcmp(str, "ss\n")))
		do_ss(*pilea, *pileb);
	else if (!(ft_strcmp(str, "pa\n")))
		do_pa(pilea, pileb);
	else if (!(ft_strcmp(str, "pb\n")))
		do_pb(pilea, pileb);
	else if (!(ft_strcmp(str, "ra\n")))
		do_ra(pilea);
	else if (!(ft_strcmp(str, "rb\n")))
		do_rb(pileb);
	else if (!(ft_strcmp(str, "rr\n")))
		do_rr(pilea, pileb);
	else if (!(ft_strcmp(str, "rra\n")))
		do_rra(pilea);
	else if (!(ft_strcmp(str, "rrb\n")))
		do_rrb(pileb);
	else if (!(ft_strcmp(str, "rrr\n")))
		do_rrr(pilea, pileb);
	else
		return (1);
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
				ft_putendl_fd("Error", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			check_av(char **av, long *nb, t_data **pilea, int x)
{
	int		y;
	int		lim;
	t_data	*newelem;
	int		tmp;

	tmp = 0;
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
					return (1);
			}
			nb[tmp] = ft_atol(av[x]);
			if (nb[tmp] < INT_MIN || nb[tmp] > INT_MAX)
				return (1);
			x++;
			tmp++;
		}
		lim = tmp;
		x = 0;
		while (x < lim)
		{
			newelem = list_newnode(nb[x]);
			list_addend(newelem, pilea);
			x++;
		}
		return (0);
	}
	return (1);
}
