/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:21:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/07 19:13:32 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct		s_data
{
	int		lima;
	int		limb;
	int		*pilea;
	int		*pileb;
}					t_data;

int					check_av(char **av, long *nb, int *pilea);
int					check_double(int ac, int *pilea);
int					check_instruction(char *str, t_data dt);
void				call_fctn(char **av, t_data dt);
void				do_sa(int lima, int *pilea);
void				do_sb(int limb, int *pileb);
void				do_ss(t_data dt);

#endif
