SRCS_ARGS		= ${addprefix ${FOLDER_ARGS}/, arg_c.c arg_d.c arg_s.c arg_x.c arg_u.c arg_percent.c arg_p.c}

FOLDER_ARGS = ./args

SRCS		= ft_printf.c reading.c treatment_args.c

OBJS		= ${SRCS_ARGS:.c=.o} ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		MAKELIBFT ${NAME}

%.o:		%.c ft_printf.h
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS} 
			ar rcs ${NAME} ${OBJS} ./libft/*.o

MAKELIBFT:
			${MAKE} -C ./libft		

clean:
			rm -f *.o ./*/*.o
			${MAKE} clean -C ./libft

fclean:		clean
			rm -f ${NAME}
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY: all clean fclean re

