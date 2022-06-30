NAME =			Cub3D

FLAGS =	-Wall -Wextra -Werror -g3

OS = $(shell uname)

BASE_SRCS =		srcs/main.c\
				srcs/ft_parsing_2.c\
				srcs/ft_parsing_3.c\
				srcs/ft_parsing_4.c\
				srcs/ft_parsing_5.c\
				srcs/my_mlx.c\
				srcs/ft_draw_2.c\
				srcs/ft_mini_map.c\
				srcs/ft_keys.c\
				srcs/ft_castray.c\
				srcs/ft_sprites.c\
				srcs/ft_save.c\
				srcs/ft_map_errors.c\
				srcs/ft_map_errors_2.c\
				srcs/ft_error.c\
				srcs/ft_extension.c

SRCS_LINUX =	srcs/ft_parsing_1_linux.c\
				srcs/ft_draw_1.c\
				srcs/ft_move2.c\
				srcs/ft_move.c\
				srcs/ft_events.c

SRCS_MAC = 		srcs/ft_parsing_1.c\
				srcs/ft_draw_1.c\
				srcs/ft_move2.c\
				srcs/ft_move.c\
				srcs/ft_events.c

SRCS_BMAC =		srcs/ft_parsing_1.c\
				srcs/ft_draw_1_bonus.c\
				srcs/ft_move2_bonus.c\
				srcs/ft_starry_night_bonus.c\
				srcs/ft_move_bonus.c\
				srcs/ft_events.c

SRCS_BLINUX =	srcs/ft_parsing_1_linux.c\
				srcs/ft_draw_1_bonus.c\
				srcs/ft_move2_bonus.c\
				srcs/ft_starry_night_bonus.c\
				srcs/ft_move_bonus.c\
				srcs/ft_events.c
	
HEADERS =   	srcs/cub3D.h


OBJS_BMAC =		${SRCS_BMAC:.c=.o}
OBJS_BLINUX =	${SRCS_BLINUX:.c=.o}
OBJS_LINUX =	${SRCS_LINUX:.c=.o}
OBJS_MAC =		${SRCS_MAC:.c=.o}
BASE_OBJS =		${BASE_SRCS:.c=.o}

ifeq ($(OS), Darwin)
OBJS = $(BASE_OBJS) $(OBJS_MAC)
BONUS = $(BASE_OBJS) $(OBJS_BMAC)
LINK = -framework OpenGL -framework AppKit
LIBS =	srcs/libft/libft.a srcs/mlx/libmlx.a
MAKE_MLX = $(MAKE) -C ./srcs/mlx
else
OBJS = $(OBJS_LINUX) $(BASE_OBJS)
BONUS = $(BASE_OBJS) $(OBJS_BLINUX)
LINK = -lm -lmlx -lX11 -lXext -lbsd -lft
LIBS =	-Lsrcs/libft -Lsrcs/mlx_Linux
MAKE_MLX = $(MAKE) -C ./srcs/mlx_Linux 
endif

all : 			$(NAME)

.%o: %.c 
	gcc -o $@ -c $< $(FLAGS)

$(NAME) :		$(OBJS)
				$(MAKE) -C ./srcs/libft
				$(MAKE_MLX)
				gcc $(LIBS) $(FLAGS) -o $(NAME) $(OBJS) $(LINK)

bonus :			$(BONUS)
				$(MAKE) -C ./srcs/libft
				$(MAKE_MLX)
				gcc $(LIBS) $(FLAGS) -o $(NAME) $(BONUS) $(LINK)
				gcc $(LIBS) $(FLAGS) -o bonus $(BONUS) $(LINK)

clean	: 
				rm -rf $(BONUS)
				rm -rf $(OBJS) $(BONUS)
				$(MAKE) -C ./srcs/libft/. clean
				$(MAKE) -C ./srcs/mlx/. clean
				$(MAKE) -C ./srcs/mlx_Linux/. clean
				rm -rf bonus

fclean  :		clean
				$(MAKE) -C ./srcs/libft/. fclean
				rm -rf $(NAME)

re      : 		fclean all

.PHONY  : 		all fclean re
