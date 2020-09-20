/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:00 by ljurdant          #+#    #+#             */
/*   Updated: 2020/02/28 19:29:18 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (NULL);
	i = 0;
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len-- > 0)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	free((void *)s);
	return (sub);
}
