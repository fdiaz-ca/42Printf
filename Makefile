# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 20:40:22 by fdiaz-ca          #+#    #+#              #
#    Updated: 2022/05/16 12:51:09 by fdiaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c

BONUS	=	ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c

OBJS	=	$(SRCS:.c=.o)

BOJS	=	$(BONUS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f


all:		$(NAME)

$(NAME):	
		gcc -c $(CFLAGS) $(SRCS)
		ar rcs $(NAME) $(OBJS)

bonus:		
		gcc -c $(CFLAGS) $(BONUS)
		ar rcs $(NAME) $(BOJS)

clean:
	$(RM) $(OBJS) $(BOJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
