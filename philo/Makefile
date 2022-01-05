CC		= gcc
NAME	= philo
SRCS	= src/main.c \
                                  src/parser/parser.c \
                                  src/exit/er_exit.c \
                                  src/init/init.c \
                                  src/utils/ft_atoi.c \
                                  src/utils/ft_strncmp.c \
                                  src/utils/cur_time.c src/cleaner/cleaner.c src/begin/begin.c src/live_circle/start_life.c src/utils/print_mes.c

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f
INCL	= ./


.c.o:
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)


$(NAME): 	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	fclean clean re bonus
