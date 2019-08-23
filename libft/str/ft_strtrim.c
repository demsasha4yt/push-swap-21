/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:23:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 19:34:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isspace(s[len - 1]))
		len--;
	i = -1;
	while (ft_isspace(s[++i]))
		len--;
	if (len <= 0)
		len = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		ptr[i] = *s++;
	ptr[i] = '\0';
	return (ptr);
}
