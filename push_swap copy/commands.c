/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:50:58 by naki              #+#    #+#             */
/*   Updated: 2023/02/24 04:30:35 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = pop_head(b, b->head);
	push_head(a, a->head, tmp);
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

	tmp = pop_head(t, t->head);
	push_tail(t, t->tail, tmp);
}

void	rrotate(t_stack *t)
{
	t_node	*tmp;

	tmp = pop_tail(t, t->tail);
	push_head(t, t->head, tmp);
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
