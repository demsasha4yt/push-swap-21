/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:15:58 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 16:29:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_move_element_to_top(t_pswap *pswap, int idx, t_stack_name name)
{
	const int	len = (name == STACK_A) ? stack_get_length(&pswap->a) :
										stack_get_length(&pswap->b);
	t_pfuncs	func;
	int			ret;

	ret = 0;
	if (idx < len - idx)
	{
		func = (name == STACK_A) ? RA_FUNC : RB_FUNC;
		ret = ps_exec_ntimes(pswap, func, idx);
	}
	else
	{
		func = (name == STACK_A) ? RRA_FUNC : RRB_FUNC;
		ret = ps_exec_ntimes(pswap, func, len - idx);
	}
	return (ret);
}
