/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pushswap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:47:51 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:22:13 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PUSHSWAP_H
# define T_PUSHSWAP_H

#include "libft.h"
#include "t_stack.h"

typedef struct		s_pushswap
{
	int				*count;
	t_list			*commands;
	int				max_count;
	int				sorted_count;
	int				count_a;
	int				i;
}					t_pushswap;

#endif
