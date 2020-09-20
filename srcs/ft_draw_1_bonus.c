/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <ljurdant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:57:12 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/22 15:14:00 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_rect(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.height)
	{
		j = 0;
		while (j < rect.width)
		{
			my_mlx_pixel_put(img, rect.x + j, rect.y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_wall_2(t_data *data, t_rect column)
{
	int		j;
	int		max;
	int		color;
	t_tex	tex;
	t_xy	tex_pos;

	tex = ft_find_tex(data);
	tex_pos.x = data->tex_x * tex.width;
	max = ft_init_j_max(*data, column.height, &j, &column.y);
	while (j < max)
	{
		if (j >= 0 && j <= column.height)
		{
			tex_pos.y = j * tex.height / column.height;
			color = *(unsigned int*)(tex.tex.addr + ((int)tex_pos.y *
			tex.tex.line_length + (int)tex_pos.x
			* (tex.tex.bits_per_pixel / 8)));
			my_mlx_pixel_put(&data->img, column.x, column.y + j, color);
		}
		j++;
	}
}

void	ft_draw_floor(t_data data)
{
	t_rect	c_rect;
	t_rect	f_rect;

	f_rect.x = 0;
	c_rect.x = 0;
	c_rect.y = 0;
	c_rect.width = data.width;
	f_rect.width = data.width;
	c_rect.height = (data.height);
	f_rect.height = (data.height) / 2 - data.offset;
	f_rect.y = (data.height) / 2 + data.offset;
	if (data.c_tex.tex.img)
		ft_starry_night(&data, c_rect);
	else
	{
		c_rect.height = (data.height / 2) + data.offset;
		ft_draw_rect(&data.img, c_rect, data.c);
	}
	ft_draw_rect(&data.img, f_rect, data.f);
}

void	ft_draw_wall_1(t_data data)
{
	t_xy	dir;
	t_rect	column;
	float	camerax;
	float	l;

	column.width = 1;
	column.x = 0;
	while (column.x < data.width)
	{
		camerax = 2 * (float)column.x / (float)data.width - 1;
		dir.x = data.dir.x + data.plane.x * camerax;
		dir.y = data.dir.y + data.plane.y * camerax;
		data.sprites.first = NULL;
		l = ft_castray(&data, dir);
		column.height = data.height / l;
		ft_draw_wall_2(&data, column);
		ft_draw_sprite_1(&data, column.x);
		column.x++;
	}
}

void	ft_draw(t_data data)
{
	ft_draw_floor(data);
	ft_draw_wall_1(data);
	ft_draw_mini_map(data);
}
