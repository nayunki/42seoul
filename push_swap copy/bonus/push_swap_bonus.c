/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:34 by naki              #+#    #+#             */
/*   Updated: 2023/02/25 16:27:11 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_stack(t_stack *a)
{
	if (is_sorted(a))
		return (1);
	return (0);
}

void	read_input(void)
{
	char	*s;
	int		fd;

	fd = open("aa.txt, O_RDONLY");
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		command("");
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2)
		return (0);
	a = ft_calloc(1, sizeof(t_stack));
	if (!a)
		error();
	parsing(av, a);
	if (a->len == 1)
		exit(0);
	read_input();
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a->head);
	free(a->dup);
	free(a);
	return (0);
}
