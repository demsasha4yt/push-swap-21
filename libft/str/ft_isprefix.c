/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:45:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 00:46:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_isprefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (ft_toupper(str[i]) == 'B'))
			return (1);
		if (base == 16 && (ft_toupper(str[i]) == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}
