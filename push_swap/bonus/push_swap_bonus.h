/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:53 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 11:12:01 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "../libft/libft.h"

# define BUFFER_SIZE 42

typedef struct s_stack
{
	int		len;
	t_node	*head;
	t_node	*tail;
}	t_stack;

/*gnl*/
char	*make_line(int fd, char *buff, char *line);
char	*get_next_line(int fd);

/*checker_utils*/
void	read_input(t_stack *a, t_stack *b);
int		do_commands(t_stack *a, t_stack *b, char *com);
void	print_output(t_stack *a, t_stack *b);

/*commands*/
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *t);
void	rotate(t_stack *t);
void	rrotate(t_stack *t);
void	command(t_stack *a, t_stack *b, char *command, int print);

/*utils*/
void	error(void);
void	command_double(t_stack *a, t_stack *b, char *command_double, int print);
int		arrlen(char **arr);
void	free_all(char **arr);
int		*put_intarr(char **arr);

/*list_utils*/
void	push_head(t_stack *t, t_node *prev_head, t_node *new_head);
void	push_tail(t_stack *t, t_node *prev_tail, t_node *new_tail);
t_node	*pop_head(t_stack *t, t_node *head);
t_node	*pop_tail(t_stack *t, t_node *tail);
t_node	*ft_lsttail(t_stack *t);

/*parsing*/
char	*join_all(char **av);
int		check_input(char *str);
int		check_repeat(int *arr, int len);
void	set_node(int *arr, int len, t_stack *a);
void	parsing(char **av, t_stack *a);

#endif
