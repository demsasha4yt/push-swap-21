/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_pushs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:46:16 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 17:50:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pa(t_pswap *pswap){
	int value;
	value = 0;

	if (pop(&pswap->b, &value))
		return (1);
	push(&pswap->a, value);
	return (0);
}

int		pb(t_pswap *pswap){
	int value;
	value = 0;

	if (pop(&pswap->a, &value))
		return (1);
	push(&pswap->b, value);
	return (0);
}
