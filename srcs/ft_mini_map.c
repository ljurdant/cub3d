/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:34:40 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/19 18:20:19 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_mini_map(t_data data)
{
	int		i;
	int		j;
	int		vision;
	t_rect	square;
	t_rect	mini_map;
	int		map_height;
	int		map_width;
	int		color;

	vision = 10;
	map_height = 0;
	while (data.map[map_height])
		map_height++;
	i = -vision / 2;
	square.height = data.height / 100;
	square.width = data.width / 100;

	ft_draw_rect(&data.img, mini_map, 0);
	while (i < vision / 2)
	{
		j = -vision / 2;
		map_width = 0;
		square.y = square.height / 2 + (i + vision/2) * square.height;
		if ((int)data.coord.y + i >= 0 && (int)data.coord.y + i < map_height)
		{	
			while (data.map[(int)data.coord.y + i][map_width])
				map_width++;
			while (j < vision / 2)
			{
				square.x = square.width + (j + vision/2) * square.width;
				if ((int)data.coord.x + j >= 0 && (int)data.coord.x + j< map_width)
				{
					color = 0;
					if (data.map[(int)data.coord.y + i][(int)data.coord.x + j] == '1')
						color = 16777215;
					else if (data.map[(int)data.coord.y + i][(int)data.coord.x + j] == '2')
						color = 16711680;
					else if (!i && !j)
						color = 255;
					else
						color = 0;
					ft_draw_rect(&data.img, square, color);
				}
				j++;
			}
		}
		i++;
	}
	// while (data.map[++i])
	// {
		// j = 0;
		// square.y = square.height / 2 + i * square.height;
		// while (data.map[i][j])
		// {
	// 		square.x = square.width + j * square.width;
	// 		if (data.map[i][j] == '1')
	// 			ft_draw_rect(&data.img, square, 16777215);
	// 		if (data.map[i][j] == '2')
	// 			ft_draw_rect(&data.img, square, 16711680);
	// 		if (data.map[i][j] != '1' && data.map[i][j] != '2')
	// 			ft_draw_rect(&data.img, square, 0);
	// 		if (i == data.coord.y && j == data.coord.x)
	// 			ft_draw_rect(&data.img, square, 255);
	// 		j++;
	// 	}
	// }
}
