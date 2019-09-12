/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:58:36 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:56:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"
#include "libft.h"

void	push(t_stack **a, int number)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->number = number;
	new->next = *a;
	*a = new;
}

void	pop(t_stack **a)
{
	t_stack *b;

	if (*a != NULL)
	{
		b = *a;
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			*a = NULL;
		free(b);
	}
}

int		exist(t_stack *a, int number)
{
	while (a != NULL)
	{
		if (a->number == number)
			return (1);
		a = a->next;
	}
	return (0);
}

void	del(t_stack **a)
{
	t_stack *ptr;

	if (a && *a)
	{
		while ((*a) != NULL)
		{
			ptr = *a;
			*a = (*a)->next;
			free(ptr);
			ptr = NULL;
		}
		free(*a);
	}
}

int		peek(t_stack *a)
{
	return a->number;
}
