/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:33:24 by ljurdant          #+#    #+#             */
/*   Updated: 2019/11/15 16:49:03 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int size;

	if (lst == NULL)
		return (0);
	size = 1;
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
