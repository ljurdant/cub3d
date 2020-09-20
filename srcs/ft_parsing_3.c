/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:57:30 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/22 17:32:56 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_coord_x(char *map_line)
{
	int i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'N' || map_line[i] == 'S'
		|| map_line[i] == 'W' || map_line[i] == 'E')
			return (i);
		i++;
	}
	return (-1);
}

t_xy	ft_parsing_coord(char **map)
{
	int		i;
	t_xy	coord;

	i = 0;
	while (map[i] && (coord.x = ft_coord_x(map[i])) < 0)
		i++;
	coord.y = i;
	return (coord);
}

t_xy	ft_parsing_pos(void)
{
	t_xy	pos;

	pos.x = 0.5;
	pos.y = 0.5;
	return (pos);
}

t_xy	ft_parsing_dir(t_data data)
{
	t_xy	dir;
	char	c;

	c = data.map[(int)data.coord.y][(int)data.coord.x];
	if (c == 'N')
	{
		dir.x = 0.001;
		dir.y = 1;
	}
	if (c == 'S')
	{
		dir.x = 0.001;
		dir.y = -1;
	}
	if (c == 'E')
	{
		dir.x = 1;
		dir.y = 0.001;
	}
	if (c == 'W')
	{
		dir.x = -1;
		dir.y = 0.001;
	}
	return (dir);
}

t_xy	ft_parsing_plane(t_data data)
{
	t_xy	plane;
	char	c;

	c = data.map[(int)data.coord.y][(int)data.coord.x];
	if (c == 'N')
	{
		plane.x = 0.66;
		plane.y = 0;
	}
	if (c == 'S')
	{
		plane.x = -0.66;
		plane.y = 0;
	}
	if (c == 'E')
	{
		plane.x = 0;
		plane.y = -0.66;
	}
	if (c == 'W')
	{
		plane.x = 0;
		plane.y = 0.66;
	}
	return (plane);
}
