/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:09:43 by naki              #+#    #+#             */
/*   Updated: 2023/02/14 20:13:41 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

# define BUFFER_SIZE		42
# define WIDTH_MAX			40
# define HEIGHT_MAX			22
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_map;
	void	*img_cha;
	void	*img_exit;
	void	*img_col;
	void	*img_wall;
	char	*name;
	char	*arr;
	int		width;
	int		height;
	int		col;
	int		cnt;
}	t_game;

char	*get_next_line(int fd);
char	*make_line(int fd, char *buff, char *line);

int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_putnbr(int nbr);
char	*ft_strdup(const char *s1, int len);
char	*ft_strdup_no_nl(char *str);
void	error(void);

int		check_name(const char *name);
char	*set_map(t_game *game);
int		is_rectangle(t_game *game);
int		is_surrounded(t_game *game);
int		check_point(t_game *game);

int		valid_map(t_game *game);
int		dfs(int start, t_game *game, char *tmp_map, char find);
int		valid_path(t_game *game);

void	set_image(t_game *game);
void	put_image(t_game *game, int hei, int wid);
void	set_window(t_game *game);

int		exit_hook(t_game *game);
int		key_hook(int keycode, t_game *game);
int		find_p(t_game *game);
void	move(t_game *game, int i);

#endif
