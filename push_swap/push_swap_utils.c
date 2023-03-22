/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:00:55 by naki              #+#    #+#             */
/*   Updated: 2023/02/24 20:34:43 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	*arr_duplicate(int *arr, int len)
{
	int	*res;
	int	i;

	res = ft_calloc(len, sizeof(int));
	if (!res)
		error();
	i = 0;
	while (i < len)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
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
