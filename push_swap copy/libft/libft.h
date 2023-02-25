/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:22:43 by naki              #+#    #+#             */
/*   Updated: 2023/02/25 16:26:57 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char const *s2, size_t len);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
void		ft_bzero(void *ptr, size_t num);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoll(const char *str);
int			ft_isdigit(int character);
t_node		*ft_lstnew(int num);
void		ft_lstclear(t_node **lst);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strchr(const char *s, int c);

//gnl strjoin 수정

#endif
