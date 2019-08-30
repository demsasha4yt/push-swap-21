/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:43:37 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/30 16:51:40 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		insertion_push_all_in_b(t_pswap *pswap, t_insertion *algo)
{
	int	tmp;

	tmp = 0;
	while (stack_get_length(&pswap->a) != 3)
	{
		peek(&pswap->a, &tmp);
		if (tmp == algo->max || tmp == algo->min || tmp == algo->average)
		{
			ps_exec(pswap, RA_FUNC);
			continue;
		}
		ps_exec(pswap, PB_FUNC);
		// if (tmp < algo->average)
		// {
		// 	ps_exec(pswap, RB_FUNC);
		// 	algo->lower_average += 1;
		// 	continue;
		// }
		// algo->larger_average += 1;
	}
	return (0);
}

static int		insertion_ra_while_cant_pa(t_pswap *pswap,
						t_insertion *algo, int value)
{
	int		tmp;

	peek (&pswap->a, &tmp);
	while (tmp < value)
	{
		ps_exec(pswap, RA_FUNC);
		algo->elements_in_bottom += 1;
		peek (&pswap->a, &tmp);
	}
	return (0);
}

int		insertion_rra_while_cant_pa(t_pswap *pswap,
						t_insertion *algo, int value)
{
	int		tmp;

	peek (&pswap->a, &tmp);
	while (tmp > value && algo->elements_in_bottom > 0)
	{
		ps_exec(pswap, RRA_FUNC);
		algo->elements_in_bottom -= 1;
		peek (&pswap->a, &tmp);
	}
	return (0);
}

static int		return_elements_in_bottom_to_top(t_pswap *pswap,
			t_insertion *algo)
{
	while (algo->elements_in_bottom)
	{
		ps_exec(pswap, RRA_FUNC);
		algo->elements_in_bottom -= 1;
	}
	return (0);
}

static int		insertion_push_in_a(t_pswap *pswap,
					t_insertion *algo, int n)
{
	int		tmp;

	while (n)
	{
		peek(&pswap->b, &tmp);
		insertion_ra_while_cant_pa(pswap, algo, tmp);
		insertion_rra_while_cant_pa(pswap, algo, tmp);
		ps_exec(pswap, PA_FUNC);
		n -= 1;
	}
	return_elements_in_bottom_to_top(pswap, algo);
	return (0);
}

int		algo_insertion(t_pswap *pswap)
{
	t_insertion algo;

	algo.max = stack_get_max(&pswap->a);
	algo.min = stack_get_min(&pswap->a);
	algo.average = stack_get_average(&pswap->a);
	algo.larger_average = 0;
	algo.lower_average = 0;
	algo.elements_in_bottom = 0;
	insertion_push_all_in_b(pswap, &algo);
	basic_3sort(pswap);
	insertion_push_in_a(pswap, &algo, stack_get_length(&pswap->b));
	return (0);
}
