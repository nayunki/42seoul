#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*make_line(int fd, char *buff, char *line);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t count);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1, int len);
char	*ft_strdup_no_nl(char *str);
int		check_name(const char *name);
char	*ft_strjoin_no_nl(char *s1, char *s2);

char	*ft_strjoin_no_nl(char *s1, char *s2)
{
	char	*line;

	if (ft_strchr(s2, '\n') >= 0)
		line = ft_strjoin(s1, s2, ft_strlen(s2) - 1);
	else
		line = ft_strjoin(s1, s2, ft_strlen(s2));
	return (line);
}

char	*ft_strdup(const char *s1, int len)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strdup_no_nl(char *str)
{
	char	*line;

	if (ft_strchr(str, '\n') >= 0)
		line = ft_strdup(str, ft_strlen(str) - 1);
	else
		line = ft_strdup(str, ft_strlen(str));
	return (line);
}

int	check_name(const char *name)
{
	int	i;

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

int main(int ac, char **av)
{
	char *name;
	char *arr;
	char *line;
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	int img_width = 64;
	int img_height = 64;
	int	fd;
	int	i;
	
	name = ft_strdup(av[1], ft_strlen(av[1]));
	if (!check_name(name))
		return (0);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	arr = ft_strdup_no_nl(get_next_line(fd));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_strjoin_no_nl(arr, line);
		free(line);
	}
	close(fd);
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
	/*
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./background.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./character.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./collectible.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./exit.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_loop(mlx);
	*/
	return (0);
}

char	*make_line(int fd, char *buff, char *line)
{
	int	i;
	int	v;

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t count)
{
	char			*arr;
	unsigned char	*temp;

	arr = malloc(count);
	if (!arr)
		return (NULL);
	temp = (unsigned char *)arr;
	while (count)
	{
		*temp = 0;
		temp++;
		count--;
	}
	return (arr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((s[i]) == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2, size_t len)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc (ft_strlen(s1) + len + 1);
	if (!strjoin)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len)
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	//free (s1);
	return (strjoin);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n)
	{
		*temp_d = *temp_s;
		temp_d++;
		temp_s++;
		n--;
	}
	return (dst);
}

