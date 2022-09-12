##
## W O R K S H O P  C R I T E R I O N
##
G++			=	gcc

RM			=	rm -rf

CPPFLAGS	+=	-Wall -Wextra -Werror #-std=c++1z

NAME		=	test_my_cat

SRCS		=	test.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS) --coverage -lcriterion

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re


