##
## W O R K S H O P  C R I T E R I O N
##

# G++			=	gcc

# RM			=	rm -rf

# CPPFLAGS	+=	-Wall -Wextra -Werror #-std=c++1z

# NAME		=	test_my_cat

# SRCS		=	test.c

# OBJS		=	$(SRCS:.c=.o)

# all			:	$(NAME)

# $(NAME)		:	$(OBJS)
# 				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS) --coverage -lcriterion

# clean		:
# 				$(RM) $(OBJS)

# fclean		:	clean
# 				$(RM) $(NAME)

# re			: fclean all

# .PHONY		: all clean fclean re


###############################################################################

G++			=	g++

SRCS_PATH	=	./src_test
INCS_PATH	=	./include_test/

NAME		=	test_my_cat

INCFLAGS	+=	-I./include_test/#$(INCS_PATH)
CRITFLAGS	+=	--coverage -lcriterion
CPPFLAGS	+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS)


SRCS		=	test3.cpp \
				$(SRCS_PATH)/src_test.cpp

OBJS		=	$(SRCS:.cpp=.o)
OBJS_GCDA	=	$(SRCS:.cpp=.gcda)
OBJS_GCNO	=	$(SRCS:.cpp=.gcno)


all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM			=	rm -rf

clean		:
				$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
				$(RM) $(SRCS_PATH)$(OBJS) $(SRCS_PATH)$(OBJS_GCDA) $(SRCS_PATH)$(OBJS_GCNO)

fclean		:	clean
				$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re


