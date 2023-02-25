/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:08 by naki              #+#    #+#             */
/*   Updated: 2023/02/24 20:59:40 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	if (!a || !b)
		error();
	parsing(av, a);
	if (a->len == 1 || is_sorted(a))
		exit (0);
	if (a->len == 2)
		sort_two(a, b);
	else if (a->len == 3)
		sort_three(a, b);
	else
		greedy(a, b);
	ft_lstclear(&a->head);
	free(a->dup);
	free(a);
	free(b);
	return (0);
}
