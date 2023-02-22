/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:35:33 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 15:44:31 by naki             ###   ########.fr       */
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

int	*bubble(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr_duplicate(arr, len));
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
