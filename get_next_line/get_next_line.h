/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:14:20 by naki              #+#    #+#             */
/*   Updated: 2022/10/10 22:16:31 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*make_line(int fd, char *buff, char *line);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t count);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
