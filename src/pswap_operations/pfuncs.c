/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfuncs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:36:58 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 20:57:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pfuncs_initialize(t_pswap *pswap)
{
	pswap->psfuncs[PA_FUNC] = &pa;
	pswap->psfuncs[PB_FUNC] = &pb;
	pswap->psfuncs[SA_FUNC] = &sa;
	pswap->psfuncs[SB_FUNC] = &sb;
	pswap->psfuncs[SS_FUNC] = &ss;
	pswap->psfuncs[RA_FUNC] = &ra;
	pswap->psfuncs[RB_FUNC] = &rb;
	pswap->psfuncs[RR_FUNC] = &rr;
	pswap->psfuncs[RRA_FUNC] = &rra;
	pswap->psfuncs[RRB_FUNC] = &rrb;
	pswap->psfuncs[RRR_FUNC] = &rrr;
	return (0);
}

int		ps_exec(t_pswap *pswap, t_pfuncs func)
{
	int ret;

	ret = pswap->psfuncs[func](pswap);
	return (ret);
}
