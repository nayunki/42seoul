/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:17:01 by naki              #+#    #+#             */
/*   Updated: 2023/02/14 20:29:31 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (ac == 2)
	{
		game->name = ft_strdup(av[1], ft_strlen(av[1]));
		if (!check_name(game->name))
			error();
		game->arr = set_map(game);
		if (valid_map(game) == 0 || valid_path(game) == 0)
			error();
		game->mlx = mlx_init();
		set_image(game);
		game->win = mlx_new_window(game->mlx, game->width * 64, \
		game->height * 64, "naki's so_long");
		set_window(game);
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_hook, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
