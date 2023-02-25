/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:38:25 by naki              #+#    #+#             */
/*   Updated: 2023/02/14 20:36:22 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_map);
	mlx_destroy_image(game->mlx, game->img_cha);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_col);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == KEY_ESC)
		exit_hook(game);
	if (keycode == KEY_UP)
		i = -(game->width);
	else if (keycode == KEY_DOWN)
		i = game->width;
	else if (keycode == KEY_LEFT)
		i = -1;
	else if (keycode == KEY_RIGHT)
		i = 1;
	else
		return (0);
	move(game, i);
	return (0);
}

int	find_p(t_game *game)
{
	int	i;

	i = 0;
	while (game->arr[i])
	{
		if (game->arr[i] == 'P')
			break ;
		i++;
	}
	return (i);
}

void	move(t_game *game, int i)
{
	int	p;

	p = find_p(game);
	if (game->arr[p + i] == 'E' && game->col == 0)
		exit_hook(game);
	else if (game->arr[p + i] == 'E')
		return ;
	if (game->arr[p + i] == '1')
		return ;
	if (game->arr[p + i] == 'C')
		game->col--;
	game->arr[p] = '0';
	p += i;
	game->arr[p] = 'P';
	game->cnt++;
	ft_putnbr(game->cnt);
	write(1, " ", 1);
	set_window(game);
	return ;
}
