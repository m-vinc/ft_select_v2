CFILE= srcs/keystroke_1.c srcs/submit.c srcs/list_1.c  srcs/signal.c srcs/display.c srcs/mis.c srcs/main.c srcs/list.c srcs/keystroke.c srcs/search.c srcs/select.c
NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

OFILE=$(CFILE:.c=.o)
FLAG= -g -I includes -Wall -Werror -Wextra  #-Wno-unused-but-set-variable
NAME= ft_select
LIB= libft/libft.a

all: $(NAME)


$(NAME): $(CFILE) $(OFILE)
	@make -C libft/
	@echo "${WARN_COLOR}$(NAME)${NO_COLOR} Generating $(NAME) -> ${OK_COLOR}$(NAME)${NO_COLOR}"
	@gcc -o $@ $(FLAG) $(OFILE) $(LIB) -ltermcap
.c.o:
	@echo "${WARN_COLOR}$(NAME):${NO_COLOR} Compile -> ${WARN_COLOR}$<${NO_COLOR} => ${OK_COLOR}$@${NO_COLOR}"
	@gcc -c $< -o $@ $(FLAG)
clean:
	@echo "${WARN_COLOR}$(NAME): ${NO_COLOR}${ERROR_COLOR}delete objects files${NO_COLOR}"
	@rm -f $(OFILE)
	@make -C libft/ clean
fclean: clean
	@echo "${WARN_COLOR}$(NAME): ${NO_COLOR}delete $(NAME)"
	@rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
