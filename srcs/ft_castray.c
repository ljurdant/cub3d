/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_castray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <ljurdant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:57:16 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 14:23:17 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_distance(t_data *data, t_xy step, t_xy coord, t_xy dir)
{
	float	wallx;
	float	l;

	if (data->side == 'W' || data->side == 'E')
	{
		l = (coord.x - (data->coord.x + data->pos.x)
			+ (1 - step.x) / 2) / dir.x;
		wallx = data->coord.y + data->pos.y - l * dir.y;
		data->tex_x = wallx - (int)wallx;
	}
	else
	{
		l = (coord.y - (data->coord.y + data->pos.y)
			+ (1 - step.y) / 2) / dir.y;
		wallx = data->coord.x + data->pos.x - l * dir.x;
		data->tex_x = wallx - (int)wallx;
	}
	return (ft_abs(l));
}

t_xy	ft_side_dist_init(t_xy dir, t_xy *step, t_data *data, t_xy delta)
{
	t_xy	side_dist;

	if (dir.x < 0)
	{
		step->x = -1;
		side_dist.x = (data->pos.x) * delta.x;
	}
	else
	{
		step->x = 1;
		side_dist.x = (1 - data->pos.x) * delta.x;
	}
	if (dir.y < 0)
	{
		step->y = 1;
		side_dist.y = (1 - data->pos.y) * delta.y;
	}
	else
	{
		step->y = -1;
		side_dist.y = (data->pos.y) * delta.y;
	}
	return (side_dist);
}

t_xy	ft_delta(t_xy dir)
{
	t_xy delta;

	if (dir.y == 0)
		delta.x = 0;
	else
		delta.x = dir.x == 0 ? 1 : ft_abs(1 / dir.x);
	if (dir.x == 0)
		delta.y = 0;
	else
		delta.y = dir.y == 0 ? 1 : ft_abs(1 / dir.y);
	return (delta);
}

void	ft_sprite_loop(t_data *data, t_xy coord, t_xy dir)
{
	t_sprite	*new;

	if (data->map[(int)coord.y][(int)coord.x] == '2')
	{
		new = ft_new_sprite(data, coord, dir);
		ft_sprite_addfront(&data->sprites, new);
	}
}

float	ft_castray(t_data *data, t_xy dir)
{
	t_xy		delta;
	t_xy		side_dist;
	t_xy		coord;
	t_xy		step;

	coord = data->coord;
	delta = ft_delta(dir);
	side_dist = ft_side_dist_init(dir, &step, data, delta);
	while (data->map[(int)coord.y][(int)coord.x] != '1')
	{
		ft_sprite_loop(data, coord, dir);
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta.x;
			coord.x += step.x;
			data->side = (dir.x < 0 ? 'W' : 'E');
		}
		else
		{
			side_dist.y += delta.y;
			coord.y += step.y;
			data->side = (dir.y < 0 ? 's' : 'N');
		}
	}
	return (ft_distance(data, step, coord, dir));
}
