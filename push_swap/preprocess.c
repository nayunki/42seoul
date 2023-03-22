/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:35:33 by naki              #+#    #+#             */
/*   Updated: 2023/02/24 20:24:15 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_stack *b)
{
	if (a->head->nbr > a->tail->nbr)
		command(a, b, "sa", 1);
}

void	sort_three(t_stack *a, t_stack *b)
{
	if ((a->head->nbr > a->head->next->nbr) && \
	(a->head->next->nbr > a->tail->nbr))
	{
		command(a, b, "sa", 1);
		command(a, b, "rra", 1);
	}
	else if ((a->head->nbr > a->tail->nbr) && \
	(a->tail->nbr > a->head->next->nbr))
		command(a, b, "ra", 1);
	else if ((a->head->next->nbr > a->tail->nbr) && \
	(a->tail->nbr > a->head->nbr))
	{
		command(a, b, "sa", 1);
		command(a, b, "ra", 1);
	}
	else if ((a->head->next->nbr > a->head->nbr) && \
	(a->head->nbr > a->tail->nbr))
		command(a, b, "rra", 1);
	else if ((a->tail->nbr > a->head->nbr) && \
	(a->head->nbr > a->head->next->nbr))
		command(a, b, "sa", 1);
}

void	bubble(t_stack *a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < a->len - 1)
	{
		j = 0;
		while (j < a->len - 1)
		{
			if (a->dup[j] > a->dup[j + 1])
			{
				tmp = a->dup[j];
				a->dup[j] = a->dup[j + 1];
				a->dup[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a->head;
	bubble(a);
	a->min = a->dup[0];
	while (i < a->len)
	{
		if (a->dup[i] != tmp->nbr)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i == a->len)
		return (1);
	return (0);
}

void	push_all(t_stack *a, t_stack *b)
{
	int		pivot_1;
	int		pivot_2;
	int		i;

	pivot_1 = a->len / 3;
	pivot_2 = pivot_1 * 2;
	pivot_1 = a->dup[pivot_1];
	pivot_2 = a->dup[pivot_2];
	i = 0;
	while (i < a->len)
	{
		if (a->head->nbr <= pivot_2)
			command(a, b, "pb", 1);
		else
			command(a, b, "ra", 1);
		if (b->len > 1 && b->head->nbr <= pivot_1)
			command(a, b, "rb", 1);
		i++;
	}
	while (a->len > 3)
		command(a, b, "pb", 1);
}
