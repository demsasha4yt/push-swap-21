/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:51:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 22:35:01 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		destroy_content(t_list **alst)
{
	if (alst == NULL || *alst == NULL)
		return ;
	free((*alst)->content);
	(*alst)->content = NULL;
	(*alst)->content_size = 0;
	free(*alst);
	*alst = NULL;
}

void		ps_destroy(t_stack **a, t_stack **b, t_pushswap **ps)
{
	t_list	*ptr;

	del(a);
	del(b);
	if (ps && *ps)
	{
		while ((*ps)->commands)
		{
			ptr = (*ps)->commands;
			(*ps)->commands = (*ps)->commands->next;
			destroy_content(&ptr);
		}
		free((*ps)->commands);
		free((*ps)->count);
		free(*ps);
	}
}

void		error(t_stack **a, t_stack **b, t_pushswap **ps)
{
	ps_destroy(a, b, ps);
	write(1, "Error\n", 6);
	exit(1);
}
