/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:08 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 15:48:22 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node *tmp_a = a->head;
	t_node *tmp_b = b->head;

	while (tmp_a != NULL)
	{
		printf("a : ");
		printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	printf("\n\n");
	while (tmp_b != NULL)
	{
		printf("b : ");
		printf("%d ", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	printf("\n\n");
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;
	int		*sorted;
	int		i;

	i = 0;
	tmp = a->head;
	sorted = bubble(a->dup, a->len);
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
	if (is_sorted(a))
		return (0); // exit으로 바꿔야하나 ?
	if (a->len == 2)
		sort_two(a, b);
	else if (a->len == 3)
		sort_three(a, b);
	else
		greedy(a, b);
	return (0);
}
