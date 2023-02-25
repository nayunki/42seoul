/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 06:16:56 by naki              #+#    #+#             */
/*   Updated: 2023/02/14 19:51:11 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_under_max(t_game *game)
{
	if (game->width <= WIDTH_MAX)
	{
		if (game->height <= HEIGHT_MAX)
			return (1);
	}
	return (0);
}

int	valid_map(t_game *game)
{
	if (is_rectangle(game))
	{
		if (is_surrounded(game))
		{
			if (check_point(game))
			{
				if (is_under_max(game))
					return (1);
			}
		}
	}
	return (0);
}

int	dfs(int start, t_game *game, char *tmp_map, char find)
{
	int		cnt;

	if (tmp_map[start] == '1')
		return (0);
	if (tmp_map[start] != 'V')
	{
		cnt = 0;
		if (tmp_map[start] == find)
			cnt++;
		tmp_map[start] = 'V';
		cnt += dfs(start - 1, game, tmp_map, find);
		cnt += dfs(start - game->width, game, tmp_map, find);
		cnt += dfs(start + 1, game, tmp_map, find);
		cnt += dfs(start + game->width, game, tmp_map, find);
		return (cnt);
	}
	return (0);
}

int	valid_path(t_game *game)
{
	char	*tmp_map_c;
	char	*tmp_map_e;
	int		cnt_c;
	int		cnt_e;
	int		p;

	p = find_p(game);
	tmp_map_c = ft_strdup(game->arr, ft_strlen(game->arr));
	tmp_map_e = ft_strdup(game->arr, ft_strlen(game->arr));
	cnt_c = dfs(p, game, tmp_map_c, 'C');
	cnt_e = dfs(p, game, tmp_map_e, 'E');
	free(tmp_map_c);
	free(tmp_map_e);
	if (cnt_c != game->col)
		return (0);
	if (cnt_e != 1)
		return (0);
	return (1);
}
