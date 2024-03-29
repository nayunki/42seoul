/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:23 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 09:15:47 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_double(t_stack *a, t_stack *b, char *command_double, int print)
{
	if (print)
	{
		write(1, command_double, ft_strlen(command_double));
		write(1, "\n", 1);
	}
	if (ft_strncmp(command_double, "rrr", 3) == 0)
	{
		command(a, b, "rra", 0);
		command(a, b, "rrb", 0);
	}
	else if (ft_strncmp(command_double, "rr", 2) == 0)
	{
		command(a, b, "ra", 0);
		command(a, b, "rb", 0);
	}
	else if (ft_strncmp(command_double, "ss", 2) == 0)
	{
		command(a, b, "sa", 0);
		command(a, b, "sb", 0);
	}
}

void	rotate_both(t_stack *a, t_stack *b, int *com_a, int *com_b)
{
	while (*com_a > 0 && *com_b > 0)
	{
		command_double(a, b, "rr", 1);
		*com_a = *com_a - 1;
		*com_b = *com_b - 1;
	}
	while (*com_a < 0 && *com_b < 0)
	{
		command_double(a, b, "rrr", 1);
		*com_a = *com_a + 1;
		*com_b = *com_b + 1;
	}
}

void	rotate_a(t_stack *a, t_stack *b, int *com_a)
{
	while (*com_a != 0)
	{
		if (*com_a > 0)
		{
			command(a, b, "ra", 1);
			*com_a = *com_a - 1;
		}
		else
		{
			command(a, b, "rra", 1);
			*com_a = *com_a + 1;
		}
	}
}

void	rotate_b(t_stack *a, t_stack *b, int *com_b)
{
	while (*com_b != 0)
	{
		if (*com_b > 0)
		{
			command(a, b, "rb", 1);
			*com_b = *com_b - 1;
		}
		else
		{
			command(a, b, "rrb", 1);
			*com_b = *com_b + 1;
		}
	}
}

unsigned int	get_abs(int num)
{
	unsigned int	ret;

	if (num < 0)
		ret = -1 * (unsigned int)num;
	else
		ret = num;
	return (ret);
}
