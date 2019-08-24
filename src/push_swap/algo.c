/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:26:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:27:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_sort_start(t_pswap *pswap)
{
	debug_print_stacks(pswap);
	ps_exec(pswap, PB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, PB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, PB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, SA_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, SB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, SS_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RA_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RR_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RRA_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RRB_FUNC);
	debug_print_stacks(pswap);
	ps_exec(pswap, RRR_FUNC);
	debug_print_stacks(pswap);
	return (0);
}
