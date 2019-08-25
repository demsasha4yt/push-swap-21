/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:15:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 20:28:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_quicksort_first_split(t_pswap *pswap)
{
	int		ret;
	int		pivot;
	t_2idxs	elems;

	pivot = 0;
	ret = 0;
	stack_get_median(&pswap->a, &pivot);
	elems = stack_get_lower_of_pivot_idxs(&pswap->a, pivot);
	while (elems.idx != -1 || elems.idx2 != -1)
	{
		stack_move_element_to_top(pswap, elems.idx, STACK_A);
		ps_exec(pswap, PB_FUNC);
		elems = stack_get_lower_of_pivot_idxs(&pswap->a, pivot);
	}
	return (0);
}

int		algo_quicksort_split_by_median(t_pswap *pswap, t_stack_name name,
				int median)
{
	int		ret;
	t_2idxs	elems;
	t_stack *current;

	current = (name == STACK_A) ? &pswap->a : &pswap->b;
	ret = 0;
	elems = (name == STACK_A) ?
			stack_get_lower_of_pivot_idxs(current, median) :
			stack_get_bigger_of_pivot_idxs(current, median);
	while (elems.idx != -1 || elems.idx2 != -1)
	{
		stack_move_element_to_top(pswap, elems.idx, name);
		ps_exec(pswap, (name == STACK_A) ? PB_FUNC : PA_FUNC);
		ret += 1;
		elems = (name == STACK_A) ?
			stack_get_lower_of_pivot_idxs(current, median) :
			stack_get_bigger_of_pivot_idxs(current, median);
	}
	return (ret);
}

// int		algo_quicksort_sort(t_pswap *pswap, t_stack_name name, int length)
// {
// 	int		ret;
// 	int		pivot;
// 	int		next_length;
// 	t_stack	*current;

// 	current = (name == STACK_A) ? &pswap->a : &pswap->b;
// 	ret = 0;
// 	pivot = 0;
// 	if (length == 2 || stack_get_length(current) == 2)
// 		try_swaps(pswap);
// 	if (length <= 2 || stack_get_length(current) <= 2)
// 		return (0);
// 	while (length >= 2)
// 	{
// 		//debug_print_stacks(pswap);
// 		stack_get_median_of_n_top_elems(current, length, &pivot);
// 		next_length = algo_quicksort_split_by_median(pswap, name, pivot);
// 		ret += next_length;
// 		algo_quicksort_sort(pswap, (name == STACK_A) ? STACK_B : STACK_A, next_length);
// 		length -= next_length;
// 	}
// 	while (ret--)
// 		ps_exec(pswap, (name == STACK_A) ? PA_FUNC : PB_FUNC);
// 	return (next_length);
// }

int		algo_quicksort_sort(t_pswap *pswap, t_stack_name name, int length)
{

}

int		algo_quicksort(t_pswap *pswap)
{
	int		ret;

	ret = 0;
	try_swaps(pswap);
	// algo_quicksort_first_split(pswap);
	algo_quicksort_sort(pswap, STACK_A, stack_get_length(&pswap->a));

	//algo_quicksort_sort(pswap, STACK_A, stack_get_length(&pswap->a));
	//debug_print_stacks(pswap);
	return (ret);
}
