/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:51:39 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 16:58:37 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstret;
	t_list	*tmp;

	if (!lst)
		return (0);
	lstret = ft_lstnew(f(lst->content));
	if (!lstret)
	{
		ft_lstclear(&lstret, del);
		return (0);
	}
	lst = lst->next;
	tmp = lstret;
	while (lst)
	{
		lstret->next = ft_lstnew(f(lst->content));
		if (!lstret->next)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		lstret = lstret->next;
		lst = lst->next;
	}
	return (tmp);
}
