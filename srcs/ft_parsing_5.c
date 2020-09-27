/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:35:49 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/27 20:01:04 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_skip_spaces(char *line, int *i)
{
	while (line[*i] && line[*i] == ' ')
		(*i)++;
}

int		ft_line_check(char *line)
{
	int i;

	i = 0;
	while (line[i] == '1' || line[i] == '0'
	|| line[i] == '2' || line[i] == ' ')
		i++;
	if (line[i])
		return (1);
	return (0);
}

void	ft_parsing_param_4(t_data *data, char *line, int fd, int i)
{
	if (!((line[i] == 'E' && line[i + 1] == 'A')
	|| (line[i] == 'S' && line[i + 1] == ' ')
	|| (line[i] == 'S' && line[i + 1] == 'O')
	|| (line[i] == 'F')
	|| (line[i] == 'C' && line[i + 1] == ' ')
	|| (line[i] == 'C' && line[i + 1] == '_')
	|| (line[i] == 'R')
	|| (line[i] == 'W' && line[i + 1] == 'E')
	|| (line[i] == 'N' && line[i + 1] == 'O')))
		ft_error_message(2, data, line);
}

void	ft_parsing_param_3(t_data *data, char **line, int fd)
{
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] == ' ')
		i++;
	if ((*line)[i] == 'E' && (*line)[i + 1] == 'A')
	{
		if (data->ea.tex.img)
			ft_error_message(9, data, *line);
		data->ea = ft_parsing_tex(data, line, fd, i);
	}
	if ((*line)[i] == 'C' && (*line)[i + 1] == '_')
	{
		if (data->c_tex.tex.img)
			ft_error_message(9, data, *line);
		data->c_tex = ft_parsing_tex(data, line, fd, i);
	}
	if ((*line)[i] == 'S' && (*line)[i + 1] != 'O')
	{
		if (data->s.tex.img)
			ft_error_message(9, data, *line);
		data->s = ft_parsing_tex(data, line, fd, i - 1);
	}
	ft_parsing_param_4(data, *line, fd, i);
}

void	ft_parsing_param_2(t_data *data, char **line, int fd)
{
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] == ' ')
		i++;
	if ((*line)[i] == 'F' && (*line)[i + 1] == ' ')
	{
		if (data->f)
			ft_error_message(9, data, *line);
		data->f = ft_parsing_color(fd, line, data);
	}
	if ((*line)[i] == 'C' && (*line)[i + 1] == ' ')
	{
		if (data->c)
			ft_error_message(9, data, *line);
		data->c = ft_parsing_color(fd, line, data);
	}
	if ((*line)[i] == 'R' && (*line)[i + 1] == ' ')
	{
		if (data->height || data->width)
			ft_error_message(9, data, *line);
		ft_parsing_r(data, line);
	}
	ft_parsing_param_3(data, line, fd);
}
