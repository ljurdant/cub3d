/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:24:28 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 18:20:38 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check(t_data *data, t_xy coord_pos)
{
	if (data->map[(int)data->coord.y][(int)(coord_pos.x)] != '1')
	{
		data->coord.x = (int)coord_pos.x;
		data->pos.x = coord_pos.x - data->coord.x;
	}
	if (data->map[(int)coord_pos.y][(int)(data->coord.x)] != '1')
	{
		data->coord.y = (int)coord_pos.y;
		data->pos.y = coord_pos.y - data->coord.y;
	}
}

void	ft_move_forward(t_data *data)
{
	t_xy	coord_pos;
	float	speed;

	speed = 0.10001;
	coord_pos.y = data->coord.y + data->pos.y - data->dir.y * speed;
	coord_pos.x = data->coord.x + data->pos.x + data->dir.x * speed;
	ft_check(data, coord_pos);
}

void	ft_move_backward(t_data *data)
{
	t_xy	coord_pos;
	float	speed;

	speed = 0.10001;
	coord_pos.y = data->coord.y + data->pos.y + data->dir.y * speed;
	coord_pos.x = data->coord.x + data->pos.x - data->dir.x * speed;
	ft_check(data, coord_pos);
}

void	ft_move_left(t_data *data)
{
	t_xy	coord_pos;
	double	speed;

	speed = 0.10001;
	coord_pos.y = data->coord.y + data->pos.y - data->dir.x * speed;
	coord_pos.x = data->coord.x + data->pos.x - data->dir.y * speed;
	ft_check(data, coord_pos);
}

void	ft_move(t_data *data)
{
	if (ft_key_check(&data->keys, 13))
		ft_move_forward(data);
	if (ft_key_check(&data->keys, 1))
		ft_move_backward(data);
	if (ft_key_check(&data->keys, 0))
		ft_move_left(data);
	if (ft_key_check(&data->keys, 2))
		ft_move_right(data);
	if (ft_key_check(&data->keys, 124))
		ft_turn_left(data);
	if (ft_key_check(&data->keys, 123))
		ft_turn_right(data);
}
