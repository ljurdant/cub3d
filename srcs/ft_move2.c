/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:42:12 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 18:25:26 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_right(t_data *data)
{
	t_xy	coord_pos;
	float	speed;

	speed = 0.10001;
	coord_pos.y = data->coord.y + data->pos.y + data->dir.x * speed;
	coord_pos.x = data->coord.x + data->pos.x + data->dir.y * speed;
	ft_check(data, coord_pos);
}

void	ft_turn_left(t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;
	float	speed;

	speed = 0.05;
	old_dir_x = data->dir.x;
	data->dir.x = data->dir.x * cos(-speed) - data->dir.y * sin(-speed);
	data->dir.y = old_dir_x * sin(-speed) + data->dir.y * cos(-speed);
	old_plane_x = data->plane.x;
	data->plane.x = data->plane.x * cos(-speed) - data->plane.y * sin(-speed);
	data->plane.y = old_plane_x * sin(-speed) + data->plane.y * cos(-speed);
}

void	ft_turn_right(t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;
	float	speed;

	speed = 0.05;
	old_dir_x = data->dir.x;
	data->dir.x = data->dir.x * cos(speed) - data->dir.y * sin(speed);
	data->dir.y = old_dir_x * sin(speed) + data->dir.y * cos(speed);
	old_plane_x = data->plane.x;
	data->plane.x = data->plane.x * cos(speed) - data->plane.y * sin(speed);
	data->plane.y = old_plane_x * sin(speed) + data->plane.y * cos(speed);
}
