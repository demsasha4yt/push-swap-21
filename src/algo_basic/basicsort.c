/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:29:37 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 06:32:10 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		basic_3sort(t_stack **a, t_pushswap **ps)
{
	int		num1;
	int		num2;
	int		num3;

	num1 = (*a) ? (*a)->number : 0;
	num2 = (*ps)->count_a > 1 ? (*a)->next->number : 0;
	num3 = (*ps)->count_a > 2 ? (*a)->next->next->number : 0;
	if (stack_get_length(*a) == 2)
	{
		if (num1 > num2)
			command_s(*a, &(*ps)->commands, "sa\n\0");
		return ;
	}
	if ((*ps)->count_a == 3 && ((num1 > num2 && num1 > num3)
			|| (num3 > num1 && num3 < num2)))
		command_r(a, &(*ps)->commands, "ra\n\0");
	if ((*ps)->count_a == 2 || (num1 > num2 && num1 < num3) ||
		(num3 > num1 && num3 < num2) || (num2 < num1 && num2 > num3))
		command_s(*a, &(*ps)->commands, "sa\n\0");
	if ((*ps)->count_a == 3 && (num2 > num1 && num2 > num3))
		command_rr(a, &(*ps)->commands, "rra\n\0");
}

static void	enumeration_a(t_stack **a, t_pushswap **ps)
{
	int		num1;
	int		num2;
	int		num3;

	num1 = (*a)->number;
	num2 = (*a)->next->number;
	num3 = (*a)->next->next->number;
	if (num1 < num2 && num2 < num3)
		return ;
	else if (num1 < num2 && num2 > num3)
	{
		command_r(a, &(*ps)->commands, "ra\n\0");
		command_s(*a, &(*ps)->commands, "sa\n\0");
		command_rr(a, &(*ps)->commands, "rra\n\0");
	}
	else if (num1 > num2 && num1 > num3)
	{
		command_s(*a, &(*ps)->commands, "sa\n\0");
		command_r(a, &(*ps)->commands, "ra\n\0");
		command_s(*a, &(*ps)->commands, "sa\n\0");
		command_rr(a, &(*ps)->commands, "rra\n\0");
	}
	if ((num1 < num2 && num1 > num3) || (num1 > num2 && num1 < num3)
		|| (num1 > num2 && num2 > num3))
		command_s(*a, &(*ps)->commands, "sa\n\0");
}

static void	enumeration_b(t_stack **a, t_stack **b, t_pushswap **ps)
{
	int num1;
	int num2;
	int num3;

	num1 = (*b)->number;
	num2 = (*b)->next->number;
	num3 = (*b)->next->next->number;
	if ((num1 < num2 && num2 > num3) || !is_sorted(*b, 3))
		command_s(*b, &(*ps)->commands, "sb\n\0");
	if ((num1 > num2 && num2 < num3) || (num1 < num2 && num1 < num3))
	{
		command_p(a, b, &(*ps)->commands, "pa\n\0");
		command_s(*b, &(*ps)->commands, "sb\n\0");
		(*ps)->sorted_count += 1;
		(*ps)->count[(*ps)->i]--;
	}
	if (num1 < num3 && num2 < num3)
	{
		command_p(a, b, &(*ps)->commands, "pa\n\0");
		command_s(*a, &(*ps)->commands, "sa\n\0");
		(*ps)->sorted_count += 1;
		(*ps)->count[(*ps)->i]--;
	}
}

void		basic_sort(t_stack **a, t_stack **b, t_pushswap **ps)
{
	if ((*ps)->count_a > 0)
	{
		if ((*ps)->count_a == 3)
			enumeration_a(a, ps);
		else if (is_sorted(*a, (*ps)->count_a))
			command_s(*a, &(*ps)->commands, "sa\n\0");
		(*ps)->sorted_count += (*ps)->count_a;
		(*ps)->count_a = 0;
	}
	if (*b && (*ps)->count[(*ps)->i] < 4 &&
		(*ps)->count[(*ps)->i] > -4)
	{
		if ((*ps)->count[(*ps)->i] < 0)
			rev_b(a, b, ps, -(*ps)->count[(*ps)->i]);
		else if ((*ps)->count[(*ps)->i] == 3)
			enumeration_b(a, b, ps);
		else if (!is_sorted(*b, (*ps)->count[(*ps)->i]) &&
				(*ps)->count[(*ps)->i] > 1)
			command_s(*b, &(*ps)->commands, "sb\n\0");
		(*ps)->sorted_count += (*ps)->count[(*ps)->i];
		while ((*ps)->count[(*ps)->i]-- > 0)
			command_p(a, b, &(*ps)->commands, "pa\n\0");
		(*ps)->count[(*ps)->i] = 0;
		(*ps)->i--;
	}
}
