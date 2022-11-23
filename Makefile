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
					srcs/initimg.c \

BONUS			=	main.c \
					srcs/plague.c \
					srcs/map.c \
					srcs/misc.c \
					srcs/game.c \
					srcs/fillmap_bonus.c \
					srcs/initimg.c \

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		=	${BONUS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C libft
	@make -C ft_printf
	@mv libft/libft.a .
	@mv ft_printf/libftprintf.a .
	cc $(OBJS) ${OBJS_GNL} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME)

bonus			: ${OBJS_GNL} ${OBJS_BONUS}
	@make -C libft
	@make -C ft_printf
	@mv libft/libft.a .
	@mv ft_printf/libftprintf.a .
	cc ${OBJS_GNL} ${OBJS_BONUS} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME)

clean			:
					make clean -C libft
					make clean -C ft_printf
					rm -rf ${OBJS} ${OBJS_GNL} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					make fclean -C ft_printf
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus
