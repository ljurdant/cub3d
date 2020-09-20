/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:12:21 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 18:13:20 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_delete(t_key_list *list, int keycode)
{
	t_key	*previous;
	t_key	*next;

	next = list->first;
	if (!next)
		return ;
	if (next->keycode == keycode)
	{
		list->first = next->next;
		free(next);
		return ;
	}
	while (next->keycode != keycode)
	{
		previous = next;
		next = next->next;
	}
	previous->next = next->next;
	free(next);
}

void	ft_key_addfront(t_key_list *list, t_key *new)
{
	new->next = list->first;
	list->first = new;
}

t_key	*ft_new_key(int keycode)
{
	t_key	*new;

	if (!(new = malloc(sizeof(t_key))))
		return (NULL);
	new->keycode = keycode;
	new->next = NULL;
	return (new);
}

int		ft_key_check(t_key_list *list, int keycode)
{
	t_key	*next;

	next = list->first;
	while (next)
	{
		if (next->keycode == keycode)
			return (1);
		next = next->next;
	}
	return (0);
}

int		key_release(int keycode, t_data *data)
{
	ft_key_delete(&data->keys, keycode);
	return (keycode);
}
