/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:04:53 by naki              #+#    #+#             */
/*   Updated: 2023/02/25 16:27:11 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "./push_swap.h"
# include "./get_next_line/get_next_line.h" //ㅈㅜㅇ보ㄱ함수 없없애애기기

char	*make_line(int fd, char *buff, char *line);
char	*get_next_line(int fd);

#endif
