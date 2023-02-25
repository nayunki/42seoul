/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:30:30 by naki              #+#    #+#             */
/*   Updated: 2022/07/24 03:35:47 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	else if (!new || !lst)
		return ;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = last;
}
