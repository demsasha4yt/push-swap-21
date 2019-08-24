/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfuncs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:36:58 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 18:40:05 by bharrold         ###   ########.fr       */
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

int		pfuncs_initialize_names(t_pswap *pswap)
{
	pswap->psfuncs_name[PA_FUNC] = ft_strdup("pa");
	pswap->psfuncs_name[PB_FUNC] = ft_strdup("pb");
	pswap->psfuncs_name[SA_FUNC] = ft_strdup("sa");
	pswap->psfuncs_name[SB_FUNC] = ft_strdup("sb");
	pswap->psfuncs_name[SS_FUNC] = ft_strdup("ss");
	pswap->psfuncs_name[RA_FUNC] = ft_strdup("ra");
	pswap->psfuncs_name[RB_FUNC] = ft_strdup("rb");
	pswap->psfuncs_name[RR_FUNC] = ft_strdup("rr");
	pswap->psfuncs_name[RRA_FUNC] = ft_strdup("rra");
	pswap->psfuncs_name[RRB_FUNC] = ft_strdup("rrb");
	pswap->psfuncs_name[RRR_FUNC] = ft_strdup("rrr");
	return (0);
}

int		pfuncs_destroy_names(t_pswap *pswap)
{
	int i;

	i = -1;
	while (++i < PFUNCTION_COUNT)
	{
		free(pswap->psfuncs_name[i]);
	}
	return (0);
}

int		common_exec(t_pswap *pswap, t_pfuncs func)
{
	int ret;

	ret = pswap->psfuncs[func](pswap);
	return (ret);
}

int		ps_exec(t_pswap *pswap, t_pfuncs func)
{
	int ret;

	ret = common_exec(pswap, func);
	ft_printf("%s\n", pswap->psfuncs_name[func]);
	return (ret);
}
