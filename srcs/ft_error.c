/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:10:32 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/26 16:50:51 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_messages(int p)
{
	if (p == 4)
		ft_put_str("Error\nNo input north texture\n");
	if (p == 5)
		ft_put_str("Error\nNo input south texture\n");
	if (p == 10)
		ft_put_str("Error\nNo input west texture\n");
	if (p == 11)
		ft_put_str("Error\nNo input east texture\n");
	if (p == 12)
		ft_put_str("Error\nNo input sprite texture\n");
	if (p == 13)
		ft_put_str("Error\nNo input value for ceiling\n");
	if (p == 14)
		ft_put_str("Error\nNo input value for floor\n");
}

void	ft_error_message(int p, t_data *data, char *line)
{
	if (p == 1)
		ft_put_str("Error\nMap\n");
	if (p == 2)
		ft_put_str("Error\n.cub file\n");
	if (p == 3 || p == 8)
		ft_put_str("Error\ncould not find file\n");
	if (p == 6)
		ft_put_str("Error\nR value\n");
	if (p == 7)
		ft_put_str("Error\nColor value\n");
	if (p == 9)
		ft_put_str("Error\nDouble Parameter\n");
	ft_messages(p);
	if (line)
	{
		while (ft_get_next_line(data->fd, &line))
			;
		free(line);
	}
	if (p != 8)
		ft_free_all(data);
	exit(0);
}

void	ft_check_params(t_data *data, char **line)
{
	if (!data->no.tex.img)
		return (ft_error_message(4, data, *line));
	if (!data->so.tex.img)
		return (ft_error_message(5, data, *line));
	if (!data->height || !data->width)
		return (ft_error_message(6, data, *line));
	if (!data->we.tex.img)
		return (ft_error_message(10, data, *line));
	if (!data->ea.tex.img)
		return (ft_error_message(11, data, *line));
	if (!data->s.tex.img)
		return (ft_error_message(12, data, *line));
	if (!data->c_tex.tex.img && !data->c)
		return (ft_error_message(13, data, *line));
	if (!data->f)
		return (ft_error_message(14, data, *line));
}

void	ft_arg_errors(int p)
{
	if (p == 1)
		ft_put_str("Error\nWrong number of arguments\n");
	if (p == 2)
		ft_put_str("Error\nInvalid argument\n");
	if (p == 3)
		ft_put_str("Error\nFile must end with \".cub\" extension\n");
	exit(0);
}
