/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:23:00 by naki              #+#    #+#             */
/*   Updated: 2023/01/26 21:03:45 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
void	handler(int sig);
void	send_byte(pid_t pid, char c);

#endif
