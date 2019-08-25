/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:30:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 15:43:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_2idxs		stack_get_max_idxs(t_stack *stack)
{
	const int	*array = stack_to_array(stack);
	const int	len = stack_get_length(stack);
	t_2idxs		result;

	result.idx = -1;
	result.idx = -1;
	if (len < 1)
		return (result);
	if (len == 1)
		result.idx = array_get_max_index(array, len);
	else
		result = array_get_max_2_idxs(array, len);
	result.idx = (result.idx != -1) ? len - result.idx - 1 : result.idx;
	result.idx2 = (result.idx2 != -1) ? len - result.idx2 - 1 : result.idx2;
	return (result);
}

t_2idxs		stack_get_min_idxs(t_stack *stack)
{
	const int	*array = stack_to_array(stack);
	const int	len = stack_get_length(stack);
	t_2idxs		result;

	result.idx = -1;
	result.idx = -1;
	if (len < 1)
		return (result);
	if (len == 1)
		result.idx = array_get_min_index(array, len);
	else
		result = array_get_min_2_idxs(array, len);
	result.idx = (result.idx != -1) ? len - result.idx - 1 : result.idx;
	result.idx2 = (result.idx2 != -1) ? len - result.idx2 - 1 : result.idx2;
	return (result);
}

t_2idxs		stack_get_lower_of_pivot_idxs(t_stack *stack, int median)
{
	const int	*array = stack_to_array(stack);
	const int	len = stack_get_length(stack);
	t_2idxs		result;

	result = array_get_lower_of_pivot_idxs(array, len, median);
	result.idx = (result.idx != -1) ? len - 1 - result.idx : result.idx;
	result.idx2 = (result.idx2 != -1) ? len - 1 - result.idx2 : result.idx2;
	return (result);
}

t_2idxs		stack_get_bigger_of_pivot_idxs(t_stack *stack, int median)
{
	const int	*array = stack_to_array(stack);
	const int	len = stack_get_length(stack);
	t_2idxs		result;

	result = array_get_bigger_of_pivot_idxs(array, len, median);
	result.idx = (result.idx != -1) ? len - 1 - result.idx : result.idx;
	result.idx2 = (result.idx2 != -1) ? len - 1 - result.idx2 : result.idx2;
	return (result);
}
