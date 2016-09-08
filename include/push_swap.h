/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:21:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/09/08 15:45:55 by stmartin         ###   ########.fr       */
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
	int				pilea;
	struct t_data	*next;
}					t_data;

typedef struct		s_datb
{
	int				limb;
	int				pileb;
	struct t_datb	*next;
}					t_datb;

int					check_av(char **av, long *nb, t_data *dta);
int					check_double(int ac, long *nb);
int					check_instruction(char *str, t_data *dta, t_datb *dtb);
void				call_fctn(char **av, t_data *dta, t_datb *dtb, long *nb);
void				do_sa(t_data *dta);
void				do_sb(t_datb *datb);
void				do_ss(t_data *dta, t_datb *dtb);

#endif
