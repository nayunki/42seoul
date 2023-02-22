/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:17:09 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 16:09:38 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_loc(int num, t_stack *a)
{
	t_node	*tmp;
	int		loc;

	tmp = a->head;
	loc = 0;
	while (tmp->next != NULL)
	{
		if (tmp->nbr < num && num < tmp->next->nbr)
			break ;
		if (tmp->nbr > num && num > tmp->next->nbr)
			break ;
		tmp = tmp->next;
		loc++;
	}
	if (loc > (a->len / 2)) // 절반보다 밑이면 ra말고 rra하려고
		loc -= a->len;
	return (loc);
}

void	find_min_rotate(t_stack *a, t_stack *b, int *com_a, int *com_b)
{ //정리해야함 ..
	t_node	*tmp;
	int		loc_a;
	int		loc_b;
	int		i;

	tmp = b->head;
	i = 0;
	while (i < b->len)
	{
		loc_a = find_loc(tmp->nbr, a);
		if (i >= (b->len + 1) / 2)
			loc_b = (b->len - i) * -1;
		else
			loc_b = i;
		if (i == 0 || (loc_a < *com_a && loc_b < *com_b))
		{
			*com_a = loc_a;
			*com_b = loc_b;
		}
		tmp = tmp->next;
		i++;
	}
}

void	last_sort(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->nbr == a->min)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < (a->len / 2))
	{
		while (a->head->nbr != a->min)
			command(a, b, "ra", 1);
	}
	else
	{
		while (a->head->nbr != a->min)
			command(a, b, "rra", 1);
	}
}

void	greedy(t_stack *a, t_stack *b)
{
	int	com_a;
	int	com_b;

	push_all(a, b);
	printf("pushed : ");
	print_stack(a, b);
	if (a->len == 3)
		sort_three(a, b);
	else if (a->len == 2)
		sort_two(a, b);
	printf("a_sorted : ");
//	print_stack(a, b);
	while (b->len)
	{
		com_a = 0;
		com_b = 0;
		find_min_rotate(a, b, &com_a, &com_b);
		rotate_both(a, b, &com_a, &com_b);
		rotate_a(a, b, com_a);
		rotate_b(a, b, com_b);
		command(a, b, "pa", 1);
	}
	last_sort(a, b);
}
