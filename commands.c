/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:50:58 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 16:30:30 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->len == 0)
		return ;
	tmp = b->head;
	if (b->len != 1)
		b->head = b->head->next;
	if (a->len == 0)
	{
		tmp->next = NULL;
		a->tail = tmp;
	}
	else
		tmp->next = a->head;
	a->head = tmp;
	a->len++;
	b->len--;
	if (b->len == 0)
	{
		b->head = NULL;
		b->tail = NULL;
	}
}

void	swap(t_stack *t)
{
	int		tmp;

	if (t->len <= 1)
		return ;
	tmp = t->head->nbr;
	t->head->nbr = t->head->next->nbr;
	t->head->next->nbr = tmp;
}

void	rotate(t_stack *t)
{
	t_node	*tmp;

	if (t->len <= 1)
		return ;
	tmp = t->head;
	t->head = t->head->next;
	t->tail->next = tmp;
	t->tail = tmp;
	tmp->next = NULL;
}

void	rrotate(t_stack *t)
{
	t_node	*tmp;
	t_node	*last;

	if (t->len <= 1)
		return ;
	tmp = t->head;
	t->head = t->tail;
	t->head->next = tmp->next;
	last = ft_lsttail(t);
	last->next = NULL;
	t->tail = last;
}

void	command(t_stack *a, t_stack *b, char *command, int print)
{
	if (print)
	{
		write(1, command, ft_strlen(command));
		write(1, "\n", 1);
	}
	if (ft_strncmp(command, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(command, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(command, "pa", 2) == 0)
		push(a, b);
	else if (ft_strncmp(command, "pb", 2) == 0)
		push(b, a);
	else if (ft_strncmp(command, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(command, "rra", 3) == 0)
		rrotate(a);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		rrotate(b);
}
