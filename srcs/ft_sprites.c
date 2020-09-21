/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:09:01 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/21 22:25:17 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_tex_x(float l2, t_data *data, t_xy diff, t_sprite *sprite)
{
	if (data->dir.y <= 0)
		sprite->tex_x = (diff.x < 0 ? 0.5 - l2 : l2 + 0.5);
	else
		sprite->tex_x = (diff.x > 0 ? 0.5 - l2 : l2 + 0.5);
}

void		ft_sprite_val(t_data *data, t_xy coord, t_xy dir, t_sprite *sprite)
{
	t_xy	diff;
	t_xy	pos;
	float	l2;
	float	cot;
	float	tan;

	coord.x = coord.x + 0.5;
	coord.y = coord.y + 0.5;
	diff.x = data->coord.x + data->pos.x - coord.x;
	diff.y = data->coord.y + data->pos.y - coord.y;
	sprite->l = sqrt(diff.x * diff.x + diff.y * diff.y);
	cot = data->dir.x / data->dir.y;
	tan = dir.y / dir.x;
	pos.x = (-coord.y + cot * coord.x + (data->coord.y + data->pos.y)
	+ tan * (data->coord.x + data->pos.x)) / (cot + tan);
	pos.y = -cot * pos.x + coord.y + cot * coord.x;
	diff.x = coord.x - pos.x;
	diff.y = coord.y - pos.y;
	l2 = sqrt(diff.x * diff.x + diff.y * diff.y);
	ft_tex_x(l2, data, diff, sprite);
	if (l2 > 0.5 || ((pos.x - data->coord.x - data->pos.x) < 0 && dir.x > 0)
	|| ((pos.x - data->coord.x - data->pos.x) > 0 && dir.x < 0)
	|| sprite->l < 0.5)
		sprite->tex_x = -1;
}

t_sprite	*ft_new_sprite(t_data *data, t_xy coord, t_xy dir)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->coord.x = coord.x;
	new->coord.y = coord.y;
	ft_sprite_val(data, coord, dir, new);
	new->height = data->height / new->l;
	new->next = NULL;
	return (new);
}

void		ft_sprite_addfront(t_list *list, t_sprite *new)
{
	new->next = list->first;
	list->first = new;
}

void		ft_free_list(t_list *list)
{
	t_sprite	*tmp;
	t_sprite	*tmp2;

	tmp = list->first;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}
