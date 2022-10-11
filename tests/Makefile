G++				=	g++

SRC_PATH		=	../sources/
INC_PATH		=	./includes/

SRC_TEST_PATH	=	./src_test/
INC_TEST_PATH	=	./include_test/

NAME			=	test_my_cat

INCFLAGS		+=	-I$(INC_PATH) -I$(INC_TEST_PATH)
CRITFLAGS		+=	--coverage -lcriterion --verbose
CPPFLAGS		+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS)


SRCS			=	test_my_cat.cpp \
					$(SRC_PATH)/my_cat.cpp \
					$(SRC_TEST_PATH)/src_test.cpp


OBJS			=	$(SRCS:.cpp=.o)
OBJS_GCDA		=	$(SRCS:.cpp=.gcda)
OBJS_GCNO		=	$(SRCS:.cpp=.gcno)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
					$(RM) $(SRC_TEST_PATH)$(OBJS) $(SRC_TEST_PATH)$(OBJS_GCDA) $(SRC_TEST_PATH)$(OBJS_GCNO)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re