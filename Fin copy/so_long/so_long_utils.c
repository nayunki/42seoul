/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:59 by naki              #+#    #+#             */
/*   Updated: 2023/02/14 21:08:03 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n') >= 0)
		line = ft_strdup(str, ft_strlen(str) - 1);
	else
		line = ft_strdup(str, ft_strlen(str));
	free(str);
	return (line);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		ft_putnbr(nbr);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	return ;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
