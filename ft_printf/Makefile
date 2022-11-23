# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2022/11/23 18:24:36 by mgamil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

DIR_SRCS	=	srcs
DIR_OBJS	=	objs

SRCS 		= 	$(DIR_SRCS)/ft_printf.c \
$(DIR_SRCS)/ft_printf_utils.c \
$(DIR_SRCS)/ft_printf_colors.c \

OBJS		=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INCLUDES	=	-I includes

CC			=	@gcc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@rm -rf $(OBJS)
			@rm -rf $(DIR_OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re