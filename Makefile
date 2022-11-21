NAME			=	so_long

GNL				=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

LIBFT			=	libft.a

PRINTF			=	libftprintf.a

SRCS			=	main.c \
					srcs/plague.c \
					srcs/map.c \
					srcs/misc.c \
					srcs/game.c \
					srcs/fillmap.c \

OBJS			=	${SRCS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

# %.o: %.c
#	 $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -g3 -c $< -o $@

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C libft
	@make -C ft_printf
	@cp libft/libft.a .
	@cp ft_printf/libftprintf.a .
	@cc $(OBJS) ${OBJS_GNL} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME)


clean			:
					make clean -C libft
					make clean -C ft_printf
					rm -rf ${OBJS} ${OBJS_GNL}

fclean			:	clean
					make fclean -C libft
					make fclean -C ft_printf
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
