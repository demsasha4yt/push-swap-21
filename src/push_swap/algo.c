/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:26:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 22:38:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_sort_start(t_pswap *pswap)
{
	ps_exec(pswap, PB_FUNC);
	ps_exec(pswap, PB_FUNC);
	ps_exec(pswap, PB_FUNC);
	ps_exec(pswap, SA_FUNC);
	ps_exec(pswap, SB_FUNC);
	ps_exec(pswap, SS_FUNC);
	ps_exec(pswap, RA_FUNC);
	ps_exec(pswap, RB_FUNC);
	ps_exec(pswap, RR_FUNC);
	ps_exec(pswap, RRA_FUNC);
	ps_exec(pswap, RRB_FUNC);
	ps_exec(pswap, RRR_FUNC);
	return (0);
}
