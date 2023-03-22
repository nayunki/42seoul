/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:20:43 by naki              #+#    #+#             */
/*   Updated: 2023/02/16 17:59:19 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(const char *name)
{
	int	i;

	if (!name)
		return (0);
	i = ft_strlen(name) - 4;
	if (name[i++] != '.')
		return (0);
	if (name[i++] != 'b')
		return (0);
	if (name[i++] != 'e')
		return (0);
	if (name[i++] != 'r')
		return (0);
	return (1);
}

char	*set_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*all;

	fd = open(game->name, O_RDONLY);
	if (fd <= 0)
		error();
	all = ft_strdup_no_nl(get_next_line(fd));
	if (!all)
		error();
	game->width = ft_strlen(all);
	while (1)
	{
		line = ft_strdup_no_nl(get_next_line(fd));
		game->height++;
		if (!line)
			break ;
		all = ft_strjoin(all, line, ft_strlen(line));
		free(line);
	}
	close (fd);
	return (all);
}

int	is_rectangle(t_game *game)
{
	if (game->width * game->height != ft_strlen(game->arr))
		return (0);
	return (1);
}

int	is_surrounded(t_game *game)
{
	int	i;

	i = 0;
	while (game->arr[i])
	{
		if (i < game->width || ft_strlen(game->arr) - game->width <= i)
		{
			if (game->arr[i] != '1')
				return (0);
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->arr[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_point(t_game *game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (game->arr[i])
	{
		if (game->arr[i] == 'C')
			game->col++;
		else if (game->arr[i] == 'P')
			p++;
		else if (game->arr[i] == 'E')
			e++;
		else if (game->arr[i] != '1' && game->arr[i] != '0')
			return (0);
		i++;
	}
	if (game->col >= 1 && p == 1 && e == 1)
		return (1);
	return (0);
}
