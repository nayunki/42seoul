/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:40:24 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 10:35:12 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_input(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		if (!do_commands(a, b, str))
			error();
		free(str);
	}
}

int	do_commands(t_stack *a, t_stack *b, char *com)
{
	if (ft_strncmp(com, "sa\n", 3) == 0)
		command(a, b, "sa", 0);
	else if (ft_strncmp(com, "sb\n", 3) == 0)
		command(a, b, "sb", 0);
	else if (ft_strncmp(com, "ss\n", 3) == 0)
		command_double(a, b, "ss", 0);
	else if (ft_strncmp(com, "pa\n", 3) == 0)
		command(a, b, "pa", 0);
	else if (ft_strncmp(com, "pb\n", 3) == 0)
		command(a, b, "pb", 0);
	else if (ft_strncmp(com, "ra\n", 3) == 0)
		command(a, b, "ra", 0);
	else if (ft_strncmp(com, "rb\n", 3) == 0)
		command(a, b, "rb", 0);
	else if (ft_strncmp(com, "rr\n", 3) == 0)
		command_double(a, b, "rr", 0);
	else if (ft_strncmp(com, "rra\n", 4) == 0)
		command(a, b, "rra", 0);
	else if (ft_strncmp(com, "rrb\n", 4) == 0)
		command(a, b, "rrb", 0);
	else if (ft_strncmp(com, "rrr\n", 4) == 0)
		command_double(a, b, "rrr", 0);
	else
		return (0);
	return (1);
}

void	print_output(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->nbr > tmp->next->nbr)
			break ;
		tmp = tmp->next;
	}
	if (b->len == 0 && a->tail == tmp)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return ;
}
