/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:56:52 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 17:58:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ra(t_pswap *pswap)
{
	int ret;

	ret = rotate(&pswap->a);
	return (ret);
}

int rb(t_pswap *pswap)
{
	int ret;

	ret = rotate(&pswap->b);
	return (ret);
}

int rr(t_pswap *pswap)
{
	int ret;

	ret = ra(pswap);
	ret = rb(pswap);
	return (ret);
}
