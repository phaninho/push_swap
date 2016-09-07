/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:21:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 15:22:44 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int			check_av(char **av, long *nb, int *pilea);
int			check_double(int ac, int *pilea);
int			check_instruction(char *str, int *lim, int *pilea);
void		call_fctn(char **av, int ac, int *pilea);
void		do_sa(int *lim, int *pilea);

#endif
