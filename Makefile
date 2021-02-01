NAME = libftprintf.a
SRCS = ft_printf.c ft_pre_output.c ft_print_nbr.c ft_print_s.c ft_print_c.c ft_print_p.c
OBJS = $(SRCS:.c=.o)
CC = gcc
INCS = -I includes
CFLAGS = -Wall -Wextra -Werror -c $(INCS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

clean :
	rm -f $(OBJS) libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all