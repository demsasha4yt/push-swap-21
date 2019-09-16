/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:28:38 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 00:29:44 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
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

int	is_valid_arg(char *arg)
{
	if (!ft_isnumeric(arg) || !is_valid_number(arg))
		return (0);
	return (1);
}
