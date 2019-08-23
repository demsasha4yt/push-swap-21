/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:49:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 20:56:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_pswap *pswap)
{
	int ret;

	ret = swap(&pswap->a);
	return (ret);
}

int		sb(t_pswap *pswap)
{
	int ret;

	ret = swap(&pswap->b);
	return (ret);
}

int		ss(t_pswap *pswap)
{
	int ret;

	ret = sa(pswap);
	ret = sb(pswap);
	return (ret);
}
