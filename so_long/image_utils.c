/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:22:37 by naki              #+#    #+#             */
/*   Updated: 2023/02/12 09:31:50 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image(t_game *game)
{
	int	hei;
	int	wid;

	game->img_map = mlx_xpm_file_to_image(game->mlx, \
	"./textures/background.xpm", &wid, &hei);
	game->img_cha = mlx_xpm_file_to_image(game->mlx, \
	"./textures/character.xpm", &wid, &hei);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, \
	"./textures/exit.xpm", &wid, &hei);
	game->img_col = mlx_xpm_file_to_image(game->mlx, \
	"./textures/collectible.xpm", &wid, &hei);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
	"./textures/wall.xpm", &wid, &hei);
}

void	put_image(t_game *game, int hei, int wid)
{
	if (game->arr[hei * game->width + wid] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, \
		wid * 64, hei * 64);
	else if (game->arr[hei * game->width + wid] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_map, \
		wid * 64, hei * 64);
	else if (game->arr[hei * game->width + wid] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_cha, \
		wid * 64, hei * 64);
	else if (game->arr[hei * game->width + wid] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
		wid * 64, hei * 64);
	else if (game->arr[hei * game->width + wid] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_col, \
		wid * 64, hei * 64);
	return ;
}

void	set_window(t_game *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_image(game, hei, wid);
			wid++;
		}
		hei++;
	}
}
