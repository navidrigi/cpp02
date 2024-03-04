CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
SRC			=	$(wildcard *.cpp)
HDR			=	$(wildcard *.hpp)
NAME		=	fixed

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

.PHONY: all clean re

clean:
	rm -f $(NAME)

re: clean all
