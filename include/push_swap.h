/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:21:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/15 16:16:33 by stmartin         ###   ########.fr       */
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
	int				lima;
	int				nb;
	struct s_data	*next;
}					t_data;

int					check_av(char **av, long *nb, t_data **dta);
int					check_double(int ac, long *nb);
int					check_instruction(char *str, t_data **dta, t_data **dtb);
void				call_fctn(char **av, t_data *dta, t_data *dtb, long *nb);
void				do_sa(t_data *dta);
void				do_sb(t_data *dtb);
void				do_ss(t_data *dta, t_data *dtb);
void				do_pb(t_data **dta, t_data **dtb);
t_data				*list_newnode(int nb);
void				list_addend(t_data *newnode, t_data **full_list);

#endif
