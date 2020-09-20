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
	t_tex	tex;
	t_xy	tex_pos;

	tex = data->c_tex;
	i = rect.x;
	while (i < rect.x + rect.width)
	{
		j = data->height / 2 - data->offset;
		tex_pos.x = i * tex.width / rect.width;
		while (j < rect.height)
		{
			tex_pos.y = tex.height * j / rect.height;
			color = *(int *)(tex.tex.addr + (int)tex_pos.y * tex.tex.line_length
					+ (int)tex_pos.x * 4);
			my_mlx_pixel_put(&data->img, i, j
			- data->height / 2 + data->offset, color);
			j++;
		}
		i++;
	}
}
