/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:57:14 by ljurdant          #+#    #+#             */
/*   Updated: 2020/02/28 19:27:13 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*s3;

	size = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	if (!(s3 = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[j])
	{
		s3[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2 && s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((void *)s1);
	return (s3);
}
