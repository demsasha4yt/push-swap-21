/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:55:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 02:48:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"
#include "libft.h"

int			is_sorted(t_stack *a, int count)
{
	int i;

	i = 0;
	while (i++ < (count - 1))
	{
		if (a->next == NULL || a->number > a->next->number)
			return (1);
		a = a->next;
	}
	return (0);
}

int			is_all_sorted(t_stack *a)
{
	int prev;

	if (a == NULL)
		return (1);
	prev = a->number;
	a = a->next;
	while (a)
	{
		if (prev > a->number)
			return (0);
		prev = a->number;
		a = a->next;
	}
	return (1);
}

void		print_stack(t_stack *a)
{
	t_stack *ptr;

	ptr = a;
	while (ptr)
	{
		ft_printf("%d\n", ptr->number);
		ptr = ptr->next;
	}
}

int			stack_get_length(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
