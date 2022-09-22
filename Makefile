G++			=	g++

SRCS_PATH	=	./sources
TST_PATH	=	./tests
INCS_PATH	=	./includes

NAME		=	my_cat
TEST_NAME 	= 	test_$(NAME)


INCFLAGS	+=	-I./includes/#$(INCS_PATH)
#LIBFLAG 	+=	-L

CPPFLAGS	+=	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z


SRCS		=	$(SRCS_PATH)/my_cat.cpp \
				$(SRCS_PATH)/main.cpp

SRC_TEST	=	tests/$(NAME)_test.cpp

OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean


all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(TST_PATH)

fclean		:	clean
				$(RM) $(NAME) $(TEST_NAME)
				@$(MAKE) $(FCLEAN) -C $(TST_PATH)

re			: fclean all

tests_run:		fclean
				@$(MAKE) -C ./tests
				./tests/$(TEST_NAME)

.PHONY		: all clean fclean re tests_run

# $(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TESTFLAGS) $(LIBFLAG)
#-L. -lmy_malloct