/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:25:31 by naki              #+#    #+#             */
/*   Updated: 2023/09/06 21:52:36 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int raycasting(t_game *game)
{
    
}

int floor_n_ceil(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->width)
    {
        y = 0;
        while (y < game->height)
        {
            game->buf[y][x] = game->c_color;
            game->buf[game->height - y - 1][x] = game->f_color;
            y++;
        }
        x++;
    }
    return (draw(game));
}

int paint(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->width)
    {
        y = 0;
        while (y < game->height)
        {
            game->img.data[y * game->width + x] = game->buf[y][x];
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
