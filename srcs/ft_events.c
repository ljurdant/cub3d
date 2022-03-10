/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:17:12 by ljurdant          #+#    #+#             */
/*   Updated: 2020/08/23 16:08:02 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_keys(t_data *data)
{
	t_key	*tmp;
	t_key	*tmp2;

	tmp = data->keys.first;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	ft_free_all(t_data *data)
{
	if (data->img_old.img)
		mlx_destroy_image(data->mlx, data->img_old.img);
	if (data->img_new.img)
		mlx_destroy_image(data->mlx, data->img_new.img);
	if (data->no.tex.img)
		mlx_destroy_image(data->mlx, data->no.tex.img);
	if (data->so.tex.img)
		mlx_destroy_image(data->mlx, data->so.tex.img);
	if (data->we.tex.img)
		mlx_destroy_image(data->mlx, data->we.tex.img);
	if (data->ea.tex.img)
		mlx_destroy_image(data->mlx, data->ea.tex.img);
	if (data->s.tex.img)
		mlx_destroy_image(data->mlx, data->s.tex.img);
	if (data->c_tex.tex.img)
		mlx_destroy_image(data->mlx, data->c_tex.tex.img);
	if (data->map)
		ft_free_table(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

int		close_window(t_data *data)
{
	ft_free_all(data);
	ft_free_keys(data);
	exit(0);
}

int		key_press(int keycode, t_data *data)
{
	t_key	*key;

	if (keycode == 65307)
	{
		return (close_window(data));
	}
	if (!ft_key_check(&data->keys, keycode))
	{
		key = ft_new_key(keycode);
		ft_key_addfront(&data->keys, key);
	}
	return (keycode);
}
