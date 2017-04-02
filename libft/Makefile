# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmorvan <vmorvan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:43:02 by vmorvan           #+#    #+#              #
#    Updated: 2017/04/02 02:21:49 by vmorvan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

NAME = libft.a

SOURCE = ./ft_atoi.c \
./ft_bzero.c \
./ft_isalnum.c \
./ft_isalpha.c \
./ft_isascii.c \
./ft_strtsplit.c \
./ft_isdigit.c \
./ft_isprint.c \
./ft_itoa.c \
./ft_lstadd.c \
./ft_lstdel.c \
./ft_lstdelone.c \
./ft_lstiter.c \
./ft_lstnew.c \
./ft_memalloc.c \
./ft_memccpy.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_memcpy.c \
./ft_memdel.c \
./ft_memmove.c \
./ft_memset.c \
./ft_putchar.c \
./ft_putchar_fd.c \
./ft_putendl.c \
./ft_putendl_fd.c \
./ft_putnbr.c \
./ft_putnbr_fd.c \
./ft_putstr.c \
./ft_putstr_fd.c \
./ft_strcat.c \
./ft_strchr.c \
./ft_strclr.c \
./ft_strcmp.c \
./ft_strcpy.c \
./ft_strdel.c \
./ft_strdup.c \
./ft_strequ.c \
./ft_striter.c \
./ft_striteri.c \
./ft_strjoin.c \
./ft_strlcat.c \
./ft_strlen.c \
./ft_strmap.c \
./ft_strmapi.c \
./ft_strncat.c \
./ft_strncmp.c \
./ft_strncpy.c \
./ft_strnequ.c \
./ft_strnew.c \
./ft_strnstr.c \
./ft_strrchr.c \
./ft_strsplit.c \
./ft_strstr.c \
./ft_strsub.c \
./ft_strtrim.c \
./ft_tolower.c \
./ft_toupper.c \
./ft_lstmap.c 

OFILE=$(SOURCE:.c=.o)

all: $(NAME) $(SOURCE)
$(NAME): $(OFILE)
	@printf "\n${WARN_COLOR}Libft:${NO_COLOR} Create library -> ${OK_COLOR}$(NAME)${NO_COLOR}\n"
	@ar rc $(NAME) $(OFILE)
.c.o:
	@printf "${WARN_COLOR}Libft:${NO_COLOR} Compile -> ${WARN_COLOR}$<${NO_COLOR} => ${OK_COLOR}$@${NO_COLOR}\033[K\r"
	@gcc -c $< -o $@ -Wall -Werror -Wextra
clean:
	@echo "${WARN_COLOR}Libft:${NO_COLOR} ${ERROR_COLOR}Delete${NO_COLOR} -> objects files."
	@rm -f $(OFILE)

fclean: clean
	@echo "${WARN_COLOR}Libft:${NO_COLOR} ${ERROR_COLOR}Delete${NO_COLOR} -> $(NAME)"
	@rm -f $(NAME)

re: fclean $(NAME)
