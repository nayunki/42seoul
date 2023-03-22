/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:05 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 10:43:16 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_head(t_stack *t, t_node *prev_head, t_node *new_head)
{
	if (!new_head)
		return ;
	if (!prev_head)
		t->tail = new_head;
	else
		new_head->next = prev_head;
	t->head = new_head;
	t->len++;
}

void	push_tail(t_stack *t, t_node *prev_tail, t_node *new_tail)
{
	if (!new_tail)
		return ;
	if (!prev_tail)
		t->head = new_tail;
	else
		prev_tail->next = new_tail;
	t->tail = new_tail;
	t->len++;
}

t_node	*pop_head(t_stack *t, t_node *head)
{
	t_node	*ret;

	ret = head;
	if (t->len == 0)
		return (NULL);
	else if (t->len == 1)
	{
		t->head = NULL;
		t->tail = NULL;
	}
	else
		t->head = t->head->next;
	ret->next = NULL;
	t->len--;
	return (ret);
}

t_node	*pop_tail(t_stack *t, t_node *tail)
{
	t_node	*ret;
	t_node	*tmp;

	ret = tail;
	if (t->len == 0)
		return (NULL);
	else if (t->len == 1)
	{
		t->head = NULL;
		t->tail = NULL;
	}
	else
	{
		tmp = ft_lsttail(t);
		tmp->next = NULL;
		t->tail = tmp;
	}
	t->len--;
	return (ret);
}

t_node	*ft_lsttail(t_stack *t)
{
	t_node	*start;

	start = t->head;
	if (!t)
		return (NULL);
	while (start->next != t->tail)
		start = start->next;
	return (start);
}
