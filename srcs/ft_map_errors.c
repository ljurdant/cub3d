/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:13:35 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/27 19:30:50 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_x(char *map_line)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'N' || map_line[i] == 'S'
		|| map_line[i] == 'W' || map_line[i] == 'E')
			count++;
		i++;
	}
	return (count);
}

void	ft_start_check(char **map, t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += ft_x(map[i]);
		i++;
	}
	if (count != 1)
		ft_error_message(1, data, NULL);
}

int		ft_vt_check(char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < j || !(str[j] == '1' || ft_is_floor(str[j])))
		return (0);
	return (1);
}

void	ft_first_and_last_line(char **map, int i, t_data *data)
{
	int	j;

	j = 0;
	while (map[i] && map[i][j])
	{
		if (!(map[i][j] == '1' || map[i][j] == ' '))
			ft_error_message(1, data, NULL);
		j++;
	}
}

void	ft_map_error(char **map, t_data *data)
{
	int	i;
	int	j;

	ft_first_and_last_line(map, 0, data);
	i = 1;
	while (map[i] && map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_floor(map[i][j]) && (!ft_vt_check(map[i - 1], j)
			|| !ft_vt_check(map[i + 1], j) || !(map[i][j - 1] == '1' ||
			ft_is_floor(map[i][j - 1])) || !(map[i][j + 1] == '1' ||
			ft_is_floor(map[i][j + 1]))))
				ft_error_message(1, data, NULL);
			if (!ft_is_map(map[i][j]))
				ft_error_message(1, data, NULL);
			j++;
		}
		i++;
	}
	ft_first_and_last_line(map, i, data);
	ft_start_check(map, data);
}
