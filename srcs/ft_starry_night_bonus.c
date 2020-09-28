/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starry_night.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:11:36 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/22 13:24:19 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_starry_night(t_data *data, t_rect rect)
{
	int		i;
	int		j;
	int		color;
	float	angle;
	t_xy	tex_pos;

	i = 0;
	angle = atan(data->dir.y / data->dir.x) + 33 * M_PI / 180;
	while (i < data->width)
	{
		j = data->height / 2 - data->offset;
		tex_pos.x = angle / ( M_PI) * data->c_tex.width;
		while (j < rect.height)
		{
			tex_pos.y = data->c_tex.height * j / rect.height;
			color = *(int *)(data->c_tex.tex.addr + (int)tex_pos.y * 
			data->c_tex.tex.line_length + (int)tex_pos.x * 4);
			my_mlx_pixel_put(&data->img, i, j
			- data->height / 2 + data->offset, color);
			j++;
		}
		i++;
		angle -= (66 * M_PI / 180) / data->width;
	}
}
