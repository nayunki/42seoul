/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:23 by naki              #+#    #+#             */
/*   Updated: 2023/02/19 21:13:51 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	command(a, b, "ra", 0);
	command(a, b, "rb", 0);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	command(a, b, "rra", 0);
	command(a, b, "rrb", 0);
	write(1, "rrr\n", 4);
}

void	rotate_both(t_stack *a, t_stack *b, int *com_a, int *com_b)
{
	while (*com_a > 0 && *com_b > 0)
	{
		rr(a, b);
		com_a--;
		com_b--;
	}
	while (*com_a < 0 && *com_b < 0)
	{
		rrr(a, b);
		com_a++;
		com_b--;
	}
}

void	rotate_a(t_stack *a, t_stack *b, int com_a)
{
	while (com_a)
	{
		if (com_a > 0)
		{
			command(a, b, "ra", 1);
			com_a--;
		}
		else
		{
			command(a, b, "rra", 1);
			com_a++;
		}
	}
}

void	rotate_b(t_stack *a, t_stack *b, int com_b)
{
	while (com_b)
	{
		if (com_b > 0)
		{
			command(a, b, "rb", 1);
			com_b--;
		}
		else
		{
			command(a, b, "rrb", 1);
			com_b++;
		}
	}
}
