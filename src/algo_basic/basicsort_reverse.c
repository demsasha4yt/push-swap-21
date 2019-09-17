/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicsort_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:04:31 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 12:04:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_element(t_stack *a, int count)
{
	int i;

	i = 0;
	while (i++ < count)
	{
		if (!a->next)
			return (0);
		a = a->next;
	}
	return (a->number);
}

static void		reverse_b(t_stack **a, t_stack **b, t_pushswap **ps, int count)
{
	int e1;
	int e2;
	int e3;

	e1 = get_element(*b, count);
	e2 = get_element(*b, count + 1);
	e3 = get_element(*b, count + 2);
	command_rr(b, &(*ps)->commands, "rrb\n\0");
	if (e1 > e2 && e1 < e3)
		command_p(a, b, &(*ps)->commands, "pa\n\0");
	command_rr(b, &(*ps)->commands, "rrb\n\0");
	if ((e1 < e2 && e1 > e3) || (e3 > e1 && e3 < e2))
		command_p(a, b, &(*ps)->commands, "pa\n\0");
	else if (e3 > e2 && e3 < e1)
		command_s(*b, &(*ps)->commands, "sb\n\0");
	if (e3 > e1 && e3 < e2)
		command_p(a, b, &(*ps)->commands, "pa\n\0");
	command_rr(b, &(*ps)->commands, "rrb\n\0");
	if (e3 > e1 && e3 < e2)
		(*ps)->count[(*ps)->i] = 1;
	else if ((e1 > e2 && e1 < e3) || (e1 < e2 && e1 > e3))
		(*ps)->count[(*ps)->i] = 2;
	(*ps)->sorted_count += 3 - (*ps)->count[(*ps)->i];
}

static void		rever_b(t_stack **a, t_stack **b, t_pushswap **ps, int count_b)
{
	while (count_b--)
	{
		command_rr(b, &(*ps)->commands, "rrb\n\0");
		command_p(a, b, &(*ps)->commands, "pa\n\0");
	}
	(*ps)->count[(*ps)->i] *= -1;
	(*ps)->sorted_count -= (*ps)->count[(*ps)->i];
	(*ps)->count[(*ps)->i] = 0;
}

void			rev_b(t_stack **a, t_stack **b, t_pushswap **ps, int count_b)
{
	int e1;
	int e2;
	int e3;
	int count;

	(*ps)->count[(*ps)->i] *= -1;
	count = (*ps)->max_count - (*ps)->sorted_count -
			(*ps)->count_a - (*ps)->count[(*ps)->i];
	e1 = get_element(*b, count);
	e2 = get_element(*b, count + 1);
	e3 = get_element(*b, count + 2);
	if (count_b == 1 || (count_b == 2 && e1 > e2) ||
		(count_b == 3 && e1 > e2 && e2 > e3))
		while (count_b--)
			command_rr(b, &(*ps)->commands, "rrb\n\0");
	else if (count_b == 2 || (count_b == 3 && e1 < e2 && e2 < e3))
		rever_b(a, b, ps, count_b);
	else
		reverse_b(a, b, ps, count);
}
