/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <ljurdant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:16:04 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/26 16:52:02 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_img_init(t_data *data)
{
	t_img	img_old;
	t_img	img_new;

	img_old.img = mlx_new_image(data->mlx, data->width, data->height);
	img_old.addr = mlx_get_data_addr(img_old.img, &img_old.bits_per_pixel
	, &img_old.line_length, &img_old.endian);
	img_new.img = mlx_new_image(data->mlx, data->width, data->height);
	img_new.addr = mlx_get_data_addr(img_new.img, &img_new.bits_per_pixel
	, &img_new.line_length, &img_new.endian);
	data->img_old = img_old;
	data->img_new = img_new;
}

int		main(int ac, char **ag)
{
	int		o;
	t_data	data;

	if (ac <= 1 || ac > 3)
		ft_arg_errors(1);
	if (ac == 3 && ft_strncmp(ag[2], "--save", 7))
		ft_arg_errors(2);
	if (!(data.mlx = mlx_init()))
	{
		printf("Error: system does not support X11 events\n");
		return (1);
	}	
	ft_extension(ag[1]);
	if ((o = open(ag[1], O_RDONLY)) < 0)
		ft_error_message(8, &data, NULL);
	ft_parsing(&data, o);
	ft_img_init(&data);
	if (ac == 3 && !ft_strncmp(ag[2], "--save", 7))
		ft_save(&data);
	data.win = mlx_new_window(data.mlx, data.width, data.height, "cub3D");
	mlx_loop_hook(data.mlx, my_mlx_image, &data);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop(data.mlx);
}
