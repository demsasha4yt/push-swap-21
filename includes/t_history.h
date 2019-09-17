/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_history.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:50:57 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 03:23:57 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HISTORY_H
# define T_HISTORY_H

typedef struct			s_history
{
	char				*cmd;
	int					*a_state;
	int					a_cnt;
	int					*b_state;
	int					b_cnt;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

#endif
