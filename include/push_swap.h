/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:21:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 13:50:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int			check_av(char **av, long *nb);
int			check_double(int ac, long *pilea);
int			check_instruction(char *str);
void		call_fctn(char **av, int ac, long *pilea);

#endif
