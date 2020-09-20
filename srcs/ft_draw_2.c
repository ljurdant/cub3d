/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:05:52 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 18:10:50 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tex	ft_find_tex(t_data *data)
{
	if (data->side == 'N')
		return (data->no);
	if (data->side == 's')
		return (data->so);
	if (data->side == 'W')
		return (data->we);
	if (data->side == 'E')
		return (data->ea);
	return (data->no);
}

int		ft_init_j_max(t_data data, int h, int *j, int *y)
{
	int	max;

	*j = 0;
	max = h;
	*y = (data.height - h) / 2 + data.offset;
	if (data.offset > 0 && (h / 2 >= data.height / 2 - data.offset))
	{
		max = h / 2 + data.height / 2 - data.offset;
		*y = data.height / 2 - (h / 2 - data.offset);
	}
	if (data.offset < 0 && (h / 2 >= data.height / 2 + data.offset))
	{
		*j = h / 2 - data.height / 2 - data.offset;
		*y = -(*j);
	}
	if (h / 2 > data.height / 2 + ft_abs(data.offset))
	{
		*j = h / 2 - data.height / 2 - data.offset;
		max = h / 2 + data.height / 2 - data.offset;
		*y = -(*j);
	}
	max -= 1;
	return (max);
}

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_draw_sprite_2(t_data *data, t_sprite *sprite, int x)
{
	int		j;
	int		max;
	int		color;
	t_tex	tex;
	t_xy	tex_pos;

	tex = data->s;
	tex_pos.x = sprite->tex_x * tex.width;
	max = ft_init_j_max(*data, sprite->height, &j, &sprite->y);
	while (j < max)
	{
		if (j >= 0 && j < sprite->height)
		{
			tex_pos.y = j * tex.height / sprite->height;
			color = *(unsigned int*)(tex.tex.addr + ((int)tex_pos.y *
			tex.tex.line_length + (int)tex_pos.x
			* (tex.tex.bits_per_pixel / 8)));
			if (color != 16777215)
				my_mlx_pixel_put(&data->img, x, sprite->y + j, color);
		}
		j++;
	}
}

void	ft_draw_sprite_1(t_data *data, int x)
{
	t_sprite	*next;

	next = data->sprites.first;
	while (next != NULL)
	{
		ft_draw_sprite_2(data, next, x);
		next = next->next;
	}
	ft_free_list(&data->sprites);
}
