/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:50:34 by ljurdant          #+#    #+#             */
/*   Updated: 2019/12/05 21:27:34 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char b)
{
	if (c == b)
		return (1);
	return (0);
}

static int	count_w(const char *str, char c)
{
	int i;
	int onoff;
	int count;

	count = 0;
	onoff = 1;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], c) == 1)
			onoff = 1;
		else
		{
			if (onoff == 1)
				count++;
			onoff = 0;
		}
		i++;
	}
	return (count);
}

static int	word_size(const char *str, int i, char c)
{
	int k;

	k = 0;
	while (is_sep(str[i], c) == 0 && str[i])
	{
		i++;
		k++;
	}
	return (k);
}

static char	*fill_tab(const char *str, int i, int size)
{
	int		k;
	char	*tab;

	k = 0;
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	while (size > k)
		tab[k++] = str[i++];
	tab[k] = '\0';
	return (tab);
}

char		**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char *) * (count_w(str, c) + 1))))
		return (NULL);
	while (str[i])
	{
		if (is_sep(str[i], c) == 1)
			i++;
		else
		{
			tab[j] = fill_tab(str, i, word_size(str, i, c));
			i += word_size(str, i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
