/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:54:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:15:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_number(t_stack **a, char *str)
{
	int	number;
	int	flag;
	int	off;
	int	lim;

	number = 0;
	flag = 1;
	if (*str == '-' || *str == '+')
	{
		flag = (*str == '-') ? -1 : 1;
		str++;
	}
	if (*str == '\0')
		error(a, NULL, NULL);
	off = flag == 1 ? INT_MAX : INT_MIN;
	lim = flag * (off % 10);
	off /= flag * 10;
	while (*str != '\0')
	{
		if (*str > '9' || *str < '0' || number * flag > off
			|| (flag * number == off && (*str - '0') > lim))
			error(a, NULL, NULL);
		number = number * 10 + flag * (*str - '0');
		str++;
	}
	return (number);
}

int			*initialize_count(int count)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (count));
	while (i < count)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

void		initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	i;
	int num;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
			error(a, NULL, NULL);
		num = put_number(a, argv[i]);
		if (exist(*b, num))
			error(a, b, NULL);
		push(b, num);
		i++;
	}
	while (*b != NULL)
	{
		push(a, (*b)->number);
		pop(b);
	}
}
