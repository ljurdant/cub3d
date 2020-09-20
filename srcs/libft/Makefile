
NAME    =   libft.a
FLAGS   =   -Wall -Wextra -Werror -D BUFFER_SIZE=50
SRCS    =   ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c ft_sqrt.c
B_SRCS  =   ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c 
OBJS    =   $(SRCS:.c=.o)
B_OBJS  =   $(B_SRCS:.c=.o)
HEADERS =   libft.h

all : $(NAME)
$(NAME) : $(OBJS)
	cc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus : $(B_OBJS) $(OBJS)
	cc $(FLAGS) -c $(SRCS) $(B_SRCS)
	ar rc $(NAME) $(OBJS) $(B_OBJS)
	ranlib $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean   :
	rm -rf $(OBJS) $(B_OBJS)

fclean  : clean
	rm -rf $(NAME)

re      : fclean all

.PHONY  : all clean bonus sanit fclean re
