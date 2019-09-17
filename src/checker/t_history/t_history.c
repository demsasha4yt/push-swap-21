/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_history.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:57:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 03:24:53 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_history	*create_history_node(t_stack *a, t_stack *b, char *cmd)
{
	t_history *node;

	node = (t_history*)malloc(sizeof(t_history));
	node->prev = NULL;
	node->next = NULL;
	node->cmd = ft_strdup(cmd);
	(void)a;
	(void)b;
	return (node);
}

t_history	*get_last_node(t_checker *checker)
{
	t_history *result;

	result = checker->history;
	if (!result)
		return (NULL);
	while (result && result->next)
		result = result->next;
	return (result);
}

void		add_to_history(t_checker *checker, t_stack *a, t_stack *b, char *cmd)
{
	t_history	*last_node;
	t_history	*new_node;

	if (checker->history == NULL)
		checker->history = create_history_node(a, b, cmd);
	else
	{
		last_node = get_last_node(checker);
		new_node = create_history_node(a, b, cmd);
		last_node->next = new_node;
	}
}

void		history_node_clear(t_history *node)
{
	free(node->cmd);
	free(node->a_state);
	free(node->b_state);
	node->cmd = NULL;
	node->a_state = NULL;
	node->b_state = NULL;
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
}

void	history_clear(t_checker *checker)
{
	t_history	*current;

	while(checker->history)
	{
		current = checker->history;
		checker->history = checker->history->next;
		history_node_clear(current);
	}
}
