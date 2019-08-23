/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_rrotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:59:15 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 18:01:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_pswap *pswap)
{
	int ret;

	ret = rrotate(&pswap->a);
	return (ret);
}


int		rrb(t_pswap *pswap)
{
	int ret;

	ret = rrotate(&pswap->b);
	return (ret);
}

int		rrr(t_pswap *pswap)
{
	int ret;

	ret = rra(pswap);
	ret = rrb(pswap);
	return (ret);
}

