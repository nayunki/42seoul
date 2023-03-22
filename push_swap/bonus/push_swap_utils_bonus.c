/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:00:55 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 10:37:27 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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

int	arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

int	*put_intarr(char **arr)
{
	int				*arr_nbr;
	int				i;
	long long		num;

	i = 0;
	arr_nbr = ft_calloc(arrlen(arr), sizeof(int));
	if (!arr_nbr)
		error();
	while (arr[i])
	{
		num = ft_atoll(arr[i]);
		if (INT_MAX < num || num < INT_MIN)
			error();
		arr_nbr[i] = num;
		i++;
	}
	return (arr_nbr);
}
