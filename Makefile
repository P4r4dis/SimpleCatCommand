G++			=	g++

RM			=	rm -rf

CPPFLAGS	+=	-Wall -Wextra -Werror -std=c++1z

LIBFLAG 	+= -I./include

TESTFLAGS	+= --coverage -lcriterion

NAME		=	my_cat

TEST_NAME 	= test_$(NAME)


SRCS		=	sources/my_cat.cpp \
				sources/my_main.cpp

OBJS		=	$(SRCS:.cpp=.o)

SRC_TEST	= tests/$(NAME)_test.cpp

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

tests_run:		fclean
				$(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloc
				./$(TEST_NAME)

cleam		:	$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME) $(TEST_NAME)

re			: fclean all

.PHONY		: all clean fclean re