/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:00:28 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 11:12:08 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_stack
{
	int		*dup;
	int		len;
	int		min;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	leak();

/*parsing.c*/
char			*join_all(char **av);
int				check_input(char *str);
int				check_repeat(int *arr, int len);
void			set_node(int *arr, int len, t_stack *a);
void			parsing(char **av, t_stack *a);

/*commands.c*/
void			push(t_stack *a, t_stack *b);
void			swap(t_stack *t);
void			rotate(t_stack *t);
void			rrotate(t_stack *t);
void			command(t_stack *a, t_stack *b, char *command, int print);

/*preprocess.c*/
void			sort_two(t_stack *a, t_stack *b);
void			sort_three(t_stack *a, t_stack *b);
void			bubble(t_stack *a);
int				is_sorted(t_stack *a);
void			push_all(t_stack *a, t_stack *b);

/*greedy_utils.c*/
void			command_double(t_stack *a, t_stack *b, char *command_double, \
				int print);
void			rotate_both(t_stack *a, t_stack *b, int *com_a, int *com_b);
void			rotate_a(t_stack *a, t_stack *b, int *com_a);
void			rotate_b(t_stack *a, t_stack *b, int *com_b);
unsigned int	get_abs(int num);

/*greedy.c*/
int				find_loc(int num, t_stack *a);
void			find_min_rotate(t_stack *a, t_stack *b, int *com_a, int *com_b);
void			last_sort(t_stack *a, t_stack *b);
void			greedy(t_stack *a, t_stack *b);

/*push_swap_utils.c*/
void			error(void);
int				*arr_duplicate(int *arr, int len);
int				arrlen(char **arr);
void			free_all(char **arr);
int				*put_intarr(char **arr);

/*list_utils.c*/
void			push_head(t_stack *t, t_node *prev_head, t_node *new_head);
void			push_tail(t_stack *t, t_node *prev_tail, t_node *new_tail);
t_node			*pop_head(t_stack *t, t_node *head);
t_node			*pop_tail(t_stack *t, t_node *tail);
t_node			*ft_lsttail(t_stack *t);

#endif
