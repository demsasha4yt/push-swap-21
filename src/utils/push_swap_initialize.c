/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:54:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 23:33:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
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

static int	is_valid_arg(char *arg)
{
	if (!ft_isnumeric(arg) || !is_valid_number(arg))
		return (0);
	return (1);
}

int			put_number(t_stack **a, char *str)
{
	if (!is_valid_arg(str))
		error(a, NULL, NULL);
	return (ft_atoi(str));
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
