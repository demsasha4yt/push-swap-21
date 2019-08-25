/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:06:57 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 16:26:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_OPERATIONS_H
# define PSWAP_OPERATIONS_H

# include "t_pswap.h"

typedef enum	e_pfuncs
{
	PA_FUNC,
	PB_FUNC,
	SA_FUNC,
	SB_FUNC,
	SS_FUNC,
	RA_FUNC,
	RB_FUNC,
	RR_FUNC,
	RRA_FUNC,
	RRB_FUNC,
	RRR_FUNC,
}				t_pfuncs;

int				pa(t_pswap *pswap);
int				pb(t_pswap *pswap);
int				sa(t_pswap *pswap);
int				sb(t_pswap *pswap);
int				ss(t_pswap *pswap);
int				ra(t_pswap *pswap);
int				rb(t_pswap *pswap);
int				rr(t_pswap *pswap);
int				rra(t_pswap *pswap);
int				rrb(t_pswap *pswap);
int				rrr(t_pswap(*pswap));

int				pfuncs_initialize(t_pswap *pswap);
int				pfuncs_initialize_names(t_pswap *pswap);
int				pfuncs_destroy_names(t_pswap *pswap);
int				ps_exec(t_pswap *pswap, t_pfuncs func);
int				ps_exec_ntimes(t_pswap *pswap, t_pfuncs func, int n);
int				debug_print_stacks(t_pswap *pswap);
int				display_error_and_exit(int error_code);

#endif
