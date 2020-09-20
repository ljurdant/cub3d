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
	t_rect	square;

	i = -1;
	square.height = data.height / 100;
	square.width = data.width / 100;
	while (data.map[++i])
	{
		j = 0;
		square.y = square.height + i * square.height;
		while (data.map[i][j])
		{
			square.x = square.width + j * square.width;
			if (data.map[i][j] == '1')
				ft_draw_rect(&data.img, square, 16777215);
			if (data.map[i][j] == '2')
				ft_draw_rect(&data.img, square, 16711680);
			if (data.map[i][j] != '1' && data.map[i][j] != '2')
				ft_draw_rect(&data.img, square, 0);
			if (i == data.coord.y && j == data.coord.x)
				ft_draw_rect(&data.img, square, 255);
			j++;
		}
	}
}
