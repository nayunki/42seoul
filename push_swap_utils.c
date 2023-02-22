/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:00:55 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 14:43:19 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
