/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:36:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 17:34:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_resolved(t_pswap *pswap)
{
	return (stack_is_empty(&pswap->b)
		&& stack_is_sorted(&pswap->a));
}
