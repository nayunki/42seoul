/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:28 by naki              #+#    #+#             */
/*   Updated: 2023/02/22 15:33:29 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
/*fot_test*/
#include <stdio.h>

typedef struct s_stack
{
	int		*dup;
	int		len;
	int		min;
	t_node	*head;
	t_node	*tail;
}	t_stack;

int		is_sorted(t_stack *a);

/*parsing.c*/
char	*join_all(char **av);
int		check_input(char *str);
int		check_repeat(int *arr, int len);
void	set_node(int *arr, int len, t_stack *a);
void	parsing(char **av, t_stack *a);

/*commands.c*/
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *t);
void	rotate(t_stack *t);
void	rrotate(t_stack *t);
void	command(t_stack *a, t_stack *b, char *command, int print);

/*preprocess.c*/
void	sort_two(t_stack *a, t_stack *b);
void	sort_three(t_stack *a, t_stack *b);
int		*bubble(int *arr, int len);
int		*put_intarr(char **arr);
void	push_all(t_stack *a, t_stack *b);

/*greedy_utils.c*/
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b, int *com_a, int *com_b);
void	rotate_a(t_stack *a, t_stack *b, int com_a);
void	rotate_b(t_stack *a, t_stack *b, int com_b); //합치기 가능

/*greedy.c*/
int		find_loc(int num, t_stack *a);
void	find_min_rotate(t_stack *a, t_stack *b, int *com_a, int *com_b);
void	last_sort(t_stack *a, t_stack *b);
void	greedy(t_stack *a, t_stack *b);

/*push_swap_utils.c*/
void	error(void);
t_node	*ft_lsttail(t_stack *t);
int		*arr_duplicate(int *arr, int len);
int		arrlen(char **arr);
void	free_all(char **arr);

/*for_test*/
void	print_stack(t_stack *a, t_stack *b);

#endif
