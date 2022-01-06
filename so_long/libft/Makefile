# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 23:24:14 by zwalad            #+#    #+#              #
#    Updated: 2021/11/24 22:50:16 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#

NAME = libft.a

CC = @cc -c

AR = @ar -rc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

SRC =	ft_bzero.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isascii.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\

BON =	ft_lstnew_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstadd_back_bonus.c\

SRCO = $(subst .c,.o,$(SRC))

BONO = $(subst .c,.o,$(BON))


all : $(NAME)

$(NAME) : $(SRCO)
	$(AR) $(NAME) $(SRCO)

bonus : $(BONO)

$(BONO) : $(BON)
	$(CC) $(BON)
	$(AR) $(NAME) $(BONO)

clean :
	$(RM) $(SRCO) $(BONO)
fclean : clean
	$(RM) $(NAME)
re : fclean all
