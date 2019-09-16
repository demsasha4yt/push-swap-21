/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:13:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 22:31:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_list	*get_fd_data(t_list **lst, int file_descriptor)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		if ((int)ptr->content_size == file_descriptor)
			return (ptr);
		ptr = ptr->next;
	}
	ptr = malloc(sizeof(t_list));
	ptr->content = malloc(1);
	ft_memcpy(ptr->content, "\0", 1);
	ptr->content_size = file_descriptor;
	ft_lstadd(lst, ptr);
	ptr = *lst;
	return (ptr);
}

char	*get_new_cur(char **current, char *buf)
{
	char	*newcurrent;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = *current;
	if (!tmp || !buf
		|| !(newcurrent = ft_strnew(ft_strlen(tmp) + ft_strlen(buf))))
		return (NULL);
	i = -1;
	j = -1;
	while (tmp[++i])
		newcurrent[i] = tmp[i];
	while (buf[++j])
		newcurrent[i++] = buf[j];
	free(*current);
	return (newcurrent);
}

char	*get_line(char *dst, char *src, int idx)
{
	int		i;

	i = 0;
	if (!(dst = ft_strnew(idx)))
		return (0);
	while (src[i] && i < idx)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*strdeli(char **current, int idx)
{
	char	*newcurrent;

	newcurrent = ft_strdup(*current + idx + 1);
	free(*current);
	return (newcurrent);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[GNL_BUFF_SIZE + 1];
	static t_list	*lst;
	t_list			*fdc;
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	fdc = get_fd_data(&lst, fd);
	while ((i = read(fd, buf, GNL_BUFF_SIZE)))
	{
		buf[i] = '\0';
		if (!(fdc->content = get_new_cur((char**)&fdc->content, buf)))
			return (-1);
		if (ft_strchr(fdc->content, '\n'))
			break ;
	}
	if (i < GNL_BUFF_SIZE && !ft_strlen(fdc->content))
		return (0);
	i = ft_strchri(fdc->content, '\n');
	*line = get_line(*line, fdc->content, i);
	if (i < (int)ft_strlen(fdc->content))
		fdc->content = strdeli((char**)&fdc->content, i);
	else
		ft_strclr(fdc->content);
	return (1);
}
