/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:14:23 by naki              #+#    #+#             */
/*   Updated: 2023/02/26 08:54:56 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(int fd, char *buff, char *line)
{
	int	i;
	int	v;

	v = 1;
	while (ft_strchr(buff, '\n') == -1)
	{
		line = ft_strjoin(line, buff, BUFFER_SIZE);
		v = read(fd, buff, BUFFER_SIZE);
		buff[v] = '\0';
		if (v <= 0)
			break ;
	}
	if (v <= 0 && !*line)
	{
		free(line);
		return (NULL);
	}
	i = ft_strchr(buff, '\n');
	if (i != -1)
	{
		line = ft_strjoin(line, buff, i + 1);
		buff = ft_memcpy(buff, buff + i + 1, BUFFER_SIZE - i);
		buff[BUFFER_SIZE - i] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	return (make_line(fd, buff, line));
}
