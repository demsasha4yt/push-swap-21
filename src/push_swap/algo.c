/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:26:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:44:09 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_sort_start(t_pswap *pswap)
{
	(void)pswap;
	if (stack_is_sorted(&pswap->a))
		ft_printf("Sorted");

	return (0);
}
