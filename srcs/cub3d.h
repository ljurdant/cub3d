/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljurdant <ljurdant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:47:57 by ljurdant          #+#    #+#             */
/*   Updated: 2020/09/26 16:47:08 by ljurdant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_Linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 20

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_tex
{
	int			height;
	int			width;
	t_img		tex;
}				t_tex;

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_xy;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rect;

typedef struct	s_sprite
{
	t_xy			coord;
	int				y;
	float			height;
	float			l;
	float			tex_x;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_list
{
	t_sprite	*first;
}				t_list;

typedef struct	s_bmh
{
	unsigned int	file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short			planes;
	short			bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	used_colors;
	unsigned int	important_colors;
}				t_bmh;

typedef struct	s_bmp
{
	t_bmh	bmh;
	char	*img;
}				t_bmp;

typedef struct	s_key
{
	int				keycode;
	struct s_key	*next;
}				t_key;

typedef struct	s_key_list
{
	t_key	*first;
}				t_key_list;

typedef struct	s_data
{
	int			height;
	int			width;
	int			offset;
	int			f;
	int			c;
	int			fd;
	void		*mlx;
	void		*win;
	char		side;
	char		**map;
	float		tex_x;
	t_img		img;
	t_img		img_old;
	t_img		img_new;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
	t_tex		s;
	t_tex		c_tex;
	t_xy		coord;
	t_xy		pos;
	t_xy		dir;
	t_xy		plane;
	t_list		sprites;
	t_key_list	keys;

}				t_data;

int				ft_is_floor(char c);
int				ft_is_floor_2(char *str, int j);
int				ft_isdigit(int c);
int				ft_search(char *line, char c);
int				ft_parsing_nb(char *line, int *i, t_data *data);
int				get_next_line(int fd, char **line);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
int				my_mlx_image(t_data *data);
int				ft_parsing_color(int fd, char **line, t_data *data);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_key_check(t_key_list *list, int keycode);
int				ft_get_next_line(int fd, char **line);
int				close_window(t_data *data);
int				ft_init_j_max(t_data data, int h, int *j, int *y);
void			ft_extension(char *str);
void			ft_arg_errors(int p);
void			ft_free_all(t_data *data);
void			ft_save(t_data *data);
void			ft_draw(t_data data);
void			ft_draw_sprite_1(t_data *data, int x);
void			ft_check(t_data *data, t_xy coord_pos);
void			ft_move(t_data *data);
void			ft_move_right(t_data *data);
void			ft_turn_left(t_data *data);
void			ft_turn_right(t_data *data);
void			ft_parsing(t_data *data, int fd);
void			ft_skip_blanks(int fd, char **line);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			ft_sprite_addfront(t_list *list, t_sprite *new);
void			ft_free_list(t_list *list);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_map_error(char **map, t_data *data);
void			ft_parsing_param(t_data *data, char **line, int fd, int *count);
void			ft_parsing_par_2(t_data *data, char **line, int fd, int *count);
void			ft_parsing_r(t_data *data, char **line);
void			ft_error_message(int p, t_data *data, char *line);
void			ft_free_table(char **str);
void			ft_look_up(t_data *data);
void			ft_look_down(t_data *data);
void			ft_key_addfront(t_key_list *list, t_key *new);
void			ft_draw_mini_map(t_data data);
void			ft_draw_rect(t_img *img, t_rect rect, int color);
void			ft_starry_night(t_data *data, t_rect rect);
void			ft_tex_init(t_data *data);
void			ft_check_params(t_data *data, char **line);
void			ft_put_str(char *str);
void			ft_c_tex(t_data *data, char **line, int fd, int *count);
char			*ft_strdup(const char *s1);
char			**ft_parsing_map(int fd, char **line);
float			ft_castray(t_data *data, t_xy dir);
float			ft_distance(t_data *data, t_xy step, t_xy coord, t_xy dir);
float			ft_abs(float x);
t_xy			ft_parsing_pos(void);
t_xy			ft_parsing_dir(t_data data);
t_xy			ft_parsing_coord(char **map);
t_xy			ft_parsing_plane(t_data data);
t_tex			ft_parsing_tex(t_data *data, char **line, int fd);
t_tex			ft_find_tex(t_data *data);
t_key			*ft_new_key(int keycode);
t_sprite		*ft_new_sprite(t_data *data, t_xy coord, t_xy dir);

#endif
