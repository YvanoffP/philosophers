CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g -I.

SRCS	=	main.c init.c error.c resolve.c tools.c
NAME	=	philo

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(OBJS):	%.o: %.c
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
			rm -rf $(SRCS:.c=.o)

fclean:		clean
			rm -rf $(NAME)

re:	fclean all

.PHONY : all re clean fclean
