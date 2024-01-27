NAME		=	push_swap
BNAME		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
HEADDIR		=	./includes/
BONUSDIR	=	./bonus/
SRCDIR		=	./srcs/

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;43m
PINK=\033[0;35m
BLUE=\033[0;34m
END=\033[0m

SRCS		=	$(SRCDIR)main.c\
				$(SRCDIR)error_check.c\
				$(SRCDIR)swap.c\
				$(SRCDIR)push.c\
				$(SRCDIR)rotate.c\
				$(SRCDIR)reverse_rotate.c\
				$(SRCDIR)sort_small.c\
				$(SRCDIR)sort_big.c\
				$(SRCDIR)put_index.c\
				$(SRCDIR)find_group_max.c\
				$(SRCDIR)place_element.c\
				$(SRCDIR)count_coups.c\
				$(SRCDIR)libft/libft_fct.c\
				$(SRCDIR)libft/libft_fct2.c\
				$(SRCDIR)libft/libft_fct3.c\
				$(SRCDIR)libft/libft_fct4.c\
				$(SRCDIR)libft/libft_fct5.c\
				$(SRCDIR)libft/libft_fct6.c\
				$(SRCDIR)libft/libft_fct7.c\

BONUS		=	$(BONUSDIR)check_correct.c\
				$(BONUSDIR)free.c\
				$(BONUSDIR)get_next_line.c\
				$(BONUSDIR)get_next_line_utils.c\
				$(BONUSDIR)init.c\
				$(BONUSDIR)main.c\
				$(BONUSDIR)make_move.c\
				$(BONUSDIR)push.c\
				$(BONUSDIR)rev_rotate.c\
				$(BONUSDIR)rotate.c\
				$(BONUSDIR)swap_bonus.c\
				$(BONUSDIR)utils_lst.c\
				$(BONUSDIR)utils.c\


OBJS		=	$(SRCS:.c=.o)
BONUSOBJS	=	$(BONUS:.c=.o)

%.o:		%.c
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADDIR)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADDIR)
		@echo "	🕹  $(GREEN)-- $(NAME) compiled --$(END) 🕹"

all:	$(NAME)

$(BNAME):	$(BONUSOBJS)
		@$(CC) $(CFLAGS) -o $(BNAME) $(BONUSOBJS) -I$(HEADDIR)
		@echo "	🕹  $(GREEN)-- $(BNAME) compiled --$(END) 🕹"

bonus:	$(BNAME)

clean:
		@$(RM) $(OBJS) $(BONUSOBJS)
		@echo "	$(PINK)--   All objects removed   --$(END) 🌪"

fclean:		clean
		@$(RM) $(NAME) $(BNAME)
		@echo "	$(RED)-- All executables removed --$(END) ❌"

re:			fclean all

.PHONY:		all re clean fclean bonus
