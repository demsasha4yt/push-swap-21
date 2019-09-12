/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:25:27 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:25:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_s(t_stack *a, t_list **commands, char *str)
{
	if (a != NULL && a->next != NULL)
	{
		a->number = a->number ^ a->next->number;
		a->next->number = a->next->number ^ a->number;
		a->number = a->number ^ a->next->number;
	}
	if (str)
		ft_lstadd_back(commands, ft_lstnew(str, 4));
}

void	command_p(t_stack **a, t_stack **b, t_list **commands, char *str)
{
	t_stack *c;

	if (*b != NULL)
	{
		c = *b;
		*b = (*b)->next;
		c->next = *a;
		*a = c;
	}
	if (str)
		ft_lstadd_back(commands, ft_lstnew(str, 4));
}

void	command_r(t_stack **a, t_list **commands, char *str)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr && ptr->next)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = *a;
		*a = (*a)->next;
		ptr->next->next = NULL;
	}
	if (str)
		ft_lstadd_back(commands, ft_lstnew(str, 4));
}

void	command_rr(t_stack **a, t_list **commands, char *str)
{
	t_stack *ptr;
	t_stack *p;

	ptr = *a;
	if (ptr && ptr->next)
	{
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		p = ptr->next;
		ptr->next = NULL;
		p->next = *a;
		*a = p;
	}
	if (str)
		ft_lstadd_back(commands, ft_lstnew(str, 5));
}
