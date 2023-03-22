/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:34 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 11:12:31 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (a->len == 1)
		exit(0);
	read_input(a, b);
	print_output(a, b);
	ft_lstclear(&a->head);
	free(a);
	free(b);
	return (0);
}
