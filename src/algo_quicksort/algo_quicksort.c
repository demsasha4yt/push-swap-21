/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 21:01:04 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 22:11:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		rev_sort_a(t_stack **a, t_stack **b,
				t_pushswap **ps, int count_a)
{
	t_stack *ptr;
	int		i;
	int		pivot;

	ptr = *a;
	i = 0;
	(*ps)->count[(*ps)->i++] = (*ps)->count_a - count_a;
	(*ps)->count_a = count_a;
	while (i++ < (*ps)->sorted_count)
		ptr = ptr->next;
	pivot = get_pivot(ptr, count_a);
	i = 0;
	while (count_a > 0)
	{
		command_rr(a, &(*ps)->commands, "rra\n\0");
		if ((*a)->number > pivot)
			i++;
		else
			command_p(b, a, &(*ps)->commands, "pb\n\0");
		count_a--;
	}
	return (i);
}

static int		sort_a(t_stack **a, t_stack **b, t_pushswap **ps)
{
	int	count_a;
	int	pivot;
	int	c_count;

	(*ps)->i++;
	c_count = (*ps)->count_a;
	pivot = get_pivot(*a, c_count);
	count_a = 0;
	while (c_count > 0)
	{
		if ((*a)->number > pivot)
		{
			count_a++;
			command_r(a, &(*ps)->commands, "ra\n\0");
		}
		else
			command_p(b, a, &(*ps)->commands, "pb\n\0");
		c_count--;
	}
	if (count_a > 3 && (*ps)->sorted_count != 0)
		count_a = rev_sort_a(a, b, ps, count_a);
	else
		while ((*ps)->sorted_count != 0 && c_count++ < count_a)
			command_rr(a, &(*ps)->commands, "rra\n\0");
	return (count_a);
}

static void		rev_sort_b(t_stack **a, t_stack **b, t_pushswap **ps, int i)
{
	t_stack *ptr;
	int		pivot;
	int		c_count;

	ptr = *b;
	if ((*ps)->count[(*ps)->i] < -3)
	{
		c_count = (*ps)->max_count - (*ps)->sorted_count -
			(*ps)->count_a + (*ps)->count[(*ps)->i];
		while (c_count--)
			ptr = ptr->next;
		pivot = get_pivot(ptr, -(*ps)->count[(*ps)->i]);
		c_count = (-1) * ((*ps)->count[(*ps)->i]);
		while (c_count-- > 0)
		{
			command_rr(b, &(*ps)->commands, "rrb\n\0");
			if ((*b)->number < pivot)
				i++;
			else
				command_p(a, b, &(*ps)->commands, "pa\n\0");
		}
		(*ps)->count_a = (-1) * (*ps)->count[(*ps)->i] - i;
		(*ps)->count[(*ps)->i] = i;
	}
}

static void		sort_b(t_stack **a, t_stack **b, t_pushswap **ps)
{
	int	c_count;
	int count_b;
	int pivot;

	if ((*ps)->count[(*ps)->i] > 0)
	{
		pivot = get_pivot(*b, (*ps)->count[(*ps)->i]);
		count_b = 0;
		c_count = (*ps)->count[(*ps)->i];
		while (c_count-- > 0)
		{
			if ((*b)->number < pivot)
			{
				count_b++;
				command_r(b, &(*ps)->commands, "rb\n\0");
			}
			else
				command_p(a, b, &(*ps)->commands, "pa\n\0");
		}
		(*ps)->count_a = (*ps)->count[(*ps)->i] - count_b;
		(*ps)->count[(*ps)->i] = ((*ps)->i > 0) ? -count_b : count_b;
	}
	else
		rev_sort_b(a, b, ps, 0);
}

void			algo_quicksort(t_stack **a, t_stack **b, t_pushswap **ps)
{
	int current;

	while (is_sorted(*a, (*ps)->max_count))
	{
		if ((*ps)->count_a == 0 && (*ps)->count[(*ps)->i] < 4
			&& (*ps)->count[(*ps)->i]  > -4)
			basic_sort(a, b, ps);
		else if ((*ps)->count_a == 0)
			sort_b(a, b, ps);
		else if (!is_sorted(*a, (*ps)->count_a))
		{
			(*ps)->sorted_count += (*ps)->count_a;
			(*ps)->count_a = 0;
		}
		else if ((*ps)->sorted_count == 0 && (*ps)->count_a < 4)
			basic_3sort(a, ps);
		else if ((*ps)->count_a < 4)
			basic_sort(a, b, ps);
		else
		{
			current = sort_a(a, b, ps);
			(*ps)->count[(*ps)->i] = (*ps)->count_a - current;
			(*ps)->count_a -= (*ps)->count[(*ps)->i];
		}
	}
}
