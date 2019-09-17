/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 03:45:37 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 04:04:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void display(t_checker *checker, t_stack **a, t_stack **b)
{
	if (checker->v_option)
		;
	else if (checker->d_option)
		debug_display(checker, a, b);
	else if (checker->c_option)
		;
	else
		default_display(checker, a, b);

}
