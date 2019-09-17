/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 03:47:53 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 06:38:04 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	default_display(t_checker *checker, t_stack **a, t_stack **b)
{
	(void)checker;
	if (is_all_sorted(*a) && stack_get_length(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
