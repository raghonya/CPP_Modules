NAME		=	interface

CXX			=	c++

CXXFLAGS	=	-fsanitize=address -g -std=c++98 -Wall -Wextra -Werror

SRCS		=	$(wildcard *.cpp)

INCS		=	$(wildcard *.hpp)

OBJDIR		=	obj

OBJS		=	$(SRCS:%.cpp=$(OBJDIR)/%.o)

all:			$(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	%.cpp $(INCS) Makefile
	$(CXX) $(CXXFLAGS) -I . -c $< -o $@

$(NAME):		$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -I . -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 