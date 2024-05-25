SRCS = #TO BE FILLED OUT!!!!!
OBJS = ${SRCS:.c=.o}
NAME = ft_printf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM}${NAME}${bonus}

re: fclean all

.PHONY: all clean fclean re