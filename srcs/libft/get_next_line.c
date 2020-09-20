/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:39:08 by ljurdant          #+#    #+#             */
/*   Updated: 2020/07/14 17:02:42 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		ft_position(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		ft_find(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			b;
	int			position;
	int			len;
	char		buffer[BUFFER_SIZE + 1];
	static char	*tmp;

	b = 1;
	while (!ft_find(tmp) && b)
	{
		if (!line || !BUFFER_SIZE || (b = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[b] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	position = ft_position(tmp);
	len = ft_strlen(tmp);
	*line = ft_substr(tmp, 0, position);
	tmp = (b ? ft_substr2(tmp, position + 1, len - position) : tmp);
	if (b == 0 && position == len)
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	return (1);
}
