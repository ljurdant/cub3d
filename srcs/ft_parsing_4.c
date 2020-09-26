/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:35:49 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/26 16:34:26 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_table(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int		ft_get_next_line(int fd, char **line)
{
	if (*line)
		free(*line);
	return (get_next_line(fd, line));
}

void	ft_tex_init(t_data *data)
{
	data->img_new.img = NULL;
	data->img_old.img = NULL;
	data->img.img = NULL;
	data->win = NULL;
	data->map = NULL;
	data->no.tex.img = NULL;
	data->so.tex.img = NULL;
	data->we.tex.img = NULL;
	data->ea.tex.img = NULL;
	data->s.tex.img = NULL;
	data->c_tex.tex.img = NULL;
	data->f = 0;
	data->c = 0;
	data->height = 0;
	data->width = 0;
}

void	ft_c_tex(t_data *data, char **line, int fd, int *count)
{
	(*count) = *count - 1;
	data->c_tex = ft_parsing_tex(data, line, fd);
}

void	ft_parsing_param(t_data *data, char **line, int fd, int *count)
{
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] == ' ')
		i++;
	if ((*line)[i] == 'N' && (*line)[i + 1] == 'O')
	{
		if (data->no.tex.img)
			ft_error_message(9, data, *line);
		data->no = ft_parsing_tex(data, line, fd);
	}
	if ((*line)[i] == 'S' && (*line)[i + 1] == 'O')
	{
		if (data->so.tex.img)
			ft_error_message(9, data, *line);
		data->so = ft_parsing_tex(data, line, fd);
	}
	if ((*line)[i] == 'W' && (*line)[i + 1] == 'E')
	{
		if (data->we.tex.img)
			ft_error_message(9, data, *line);
		data->we = ft_parsing_tex(data, line, fd);
	}
	ft_parsing_par_2(data, line, fd, count);
	(*count)++;
}
