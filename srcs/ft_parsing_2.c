/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:22:08 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/23 15:53:48 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsing_nb(char *line, int *i, t_data *data)
{
	int		n;

	n = 0;
	while (line[*i] == ',' || line[*i] == ' ')
		(*i)++;
	if (line[*i] < '0' || line[*i] > '9')
		ft_error_message(2, data, line);
	while (line[*i] && (line[*i] >= '0' && line[*i] <= '9'))
	{
		n = 10 * n + line[*i] - 48;
		(*i)++;
	}
	if (n < 0)
		n = 2147483647;
	return (n);
}

char	**ft_strstrdup(char **src)
{
	int		i;
	char	**dest;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc(sizeof(char *) * (i + 1))))
		dest = malloc(0);
	i = -1;
	while (src[++i])
		dest[i] = ft_strdup(src[i]);
	dest[i] = NULL;
	return (dest);
}

void	ft_loop_map(char **line, char ***map, char ***tmp, int i)
{
	int j;

	if (!((*map) = malloc(sizeof(char *) * (i + 1))))
		return ;
	j = -1;
	while ((*tmp)[++j])
		(*map)[j] = ft_strdup((*tmp)[j]);
	ft_free_table((*tmp));
	(*map)[i - 1] = ft_strdup(*line);
	(*map)[i] = NULL;
	(*tmp) = ft_strstrdup((*map));
}

char	**ft_parsing_map(int fd, char **line)
{
	int		i;
	int		r;
	char	**tmp;
	char	**map;

	r = 1;
	ft_skip_blanks(fd, line);
	while (ft_search(*line, '1') < 0)
		r = ft_get_next_line(fd, line);
	if (!(tmp = malloc(sizeof(char *))))
		return (NULL);
	tmp[0] = NULL;
	i = 1;
	map = NULL;
	while (r >= 1)
	{
		ft_loop_map(line, &map, &tmp, i);
		r = ft_get_next_line(fd, line);
		if (r >= 1)
			ft_free_table(map);
		i++;
	}
	ft_free_table(tmp);
	return (map);
}

int		ft_parsing_color(int fd, char **line, t_data *data)
{
	int				i;
	int				r;
	int				g;
	int				b;
	int				color;

	i = 1;
	while (ft_search(*line, ',') < 0)
		ft_get_next_line(fd, line);
	r = ft_parsing_nb(*line, &i, data);
	g = ft_parsing_nb(*line, &i, data);
	b = ft_parsing_nb(*line, &i, data);
	if (r > 255 || g > 255 || b > 255)
		ft_error_message(7, data, *line);
	color = (0 << 24 | r << 16 | g << 8 | b);
	while ((*line)[i])
	{
		if ((*line)[i] != ' ')
			ft_error_message(7, data, *line);
		i++;
	}
	return (color);
}
