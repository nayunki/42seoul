/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:58:16 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 14:42:06 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_all(char **av)
{
	char	*all;
	int		i;

	i = 1;
	all = ft_calloc(1, 1);
	if (!all)
		error();
	while (av[i])
	{
		all = ft_strjoin(all, " ");
		all = ft_strjoin(all, av[i]);
		i++;
	}
	return (all);
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	check_repeat(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len && arr[j])
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	set_node(int *arr, int len, t_stack *a)
{
	t_node	*tmp;
	int		i;

	tmp = ft_lstnew(arr[0]);
	a->head = tmp;
	a->tail = tmp;
	i = 1;
	while (i < len)
	{
		tmp = ft_lstnew(arr[i]);
		a->tail->next = tmp;
		a->tail = tmp;
		i++;
	}
	return ;
}

void	parsing(char **av, t_stack *a)
{
	char	*str;
	char	**arr;
	int		*arr_nbr;

	str = join_all(av);
	if (!check_input(str))
		error();
	arr = ft_split(str, ' ');
	if (!arr)
		error();
	a->len = arrlen(arr);
	arr_nbr = put_intarr(arr);
	if (!check_repeat(arr_nbr, a->len))
		error();
	set_node(arr_nbr, a->len, a);
	a->dup = arr_duplicate(arr_nbr, a->len);
	free(str);
	free_all(arr);
	free(arr_nbr);
}
