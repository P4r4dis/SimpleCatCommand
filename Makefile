G++			=	g++
CC			=	gcc

RM			=	rm -rf

CPPFLAGS	+=	-Wall -Wextra -Werror -std=c++1z

LIBFLAG 	+= -I./include

TESTFLAGS	+= --coverage -lcriterion

NAME		=	my_cat

TEST_NAME 	= test_$(NAME)


SRCS		=	sources/my_cat.cpp \
				sources/my_main.cpp

SRC_TEST	= tests/$(NAME)_test.c

SRCS_PATH	=	sources/
TST_PATH	=	tests/

CLEAN		=	clean
FCLEAN		=	fclean

OBJS		=	$(SRCS:.cpp=.o)



all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean		: 	clean
				$(RM) $(NAME) $(TEST_NAME)
				@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re: fclean all

tests_run:		fclean
				@$(MAKE) -C ./tests
				./tests/$(TEST_NAME)

.PHONY: all clean fclean re tests_run
# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct


