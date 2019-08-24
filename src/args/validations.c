/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:04:51 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:30:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid_number(char *str)
{
	int sign;
	int len;

	sign = 1;
	if (str == NULL || *str == '\0')
		return (0);
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	len = ft_strlen(str);
	if (len > 10 || (sign > 0
			&& len == 10 && ft_strncmp(str, "2147483647", 10) > 0))
		return (0);
	if (sign < 0
		&& len == 10 && ft_strncmp(str, "2147483648", 10) > 0)
		return (0);
	return (1);
}

int		is_valid_arg(char *arg)
{
	if (!ft_isnumeric(arg) || !is_valid_number(arg))
		return (0);
	return (1);
}

int		is_arg_already_exist(t_stack *a, int arg)
{
	int		tmp;
	t_stack	tmp_stack;

	copy_stack(&tmp_stack, a);
	while (!stack_is_empty(&tmp_stack))
	{
		pop(&tmp_stack, &tmp);
		if (tmp == arg)
			return (1);
	}
	destroy_stack(&tmp_stack);
	return (0);
}
