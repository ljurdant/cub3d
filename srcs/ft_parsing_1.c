/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <ljurdant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:11:11 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/13 22:23:42 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_search(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_skip_blanks(int fd, char **line)
{
	ft_get_next_line(fd, line);
	while (*line == NULL || (*line)[0] == '\0')
		ft_get_next_line(fd, line);
}

void	ft_parsing_r(t_data *data, char **line)
{
	int		i;

	i = 1;
	data->width = ft_parsing_nb(*line, &i, data);
	data->height = ft_parsing_nb(*line, &i, data);
	if (data->width > 2560)
		data->width = 2560;
	if (data->height > 1440)
		data->height = 1440;
	while ((*line)[i])
	{
		if ((*line)[i] != ' ')
			ft_error_message(6, data, *line);
		i++;
	}
}

t_tex	ft_parsing_tex(t_data *data, char **line, int fd)
{
	int		i;
	int		j;
	int		size;
	char	*str;
	t_tex	tex;

	while ((i = ft_search(*line, '.')) < 0)
		ft_get_next_line(fd, line);
	size = 0;
	while ((*line)[i + size] && (*line)[i + size] != ' ')
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		str = malloc(0);
	j = 0;
	while (j < size)
		str[j++] = (*line)[i++];
	str[size] = '\0';
	tex.tex.img = mlx_xpm_file_to_image(data->mlx,
	str, &tex.width, &tex.height);
	free(str);
	if (!tex.tex.img)
		ft_error_message(3, data, *line);
	tex.tex.addr = mlx_get_data_addr(tex.tex.img,
	&tex.tex.bits_per_pixel, &tex.tex.line_length, &tex.tex.endian);
	return (tex);
}

void	ft_parsing(t_data *data, int fd)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	data->fd = fd;
	ft_tex_init(data);
	while (count < 8)
	{
		ft_skip_blanks(fd, &line);
		ft_parsing_param(data, &line, fd, &count);
	}
	ft_check_params(data, &line);
	data->map = ft_parsing_map(fd, &line);
	free(line);
	ft_map_error(data->map, data);
	data->coord = ft_parsing_coord(data->map);
	data->pos = ft_parsing_pos();
	data->dir = ft_parsing_dir(*data);
	data->plane = ft_parsing_plane(*data);
	data->keys.first = NULL;
	data->offset = 0;
}
