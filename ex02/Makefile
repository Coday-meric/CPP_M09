NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

FLAG = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME):	$(OBJ)
		c++ $(FLAG) -o $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean all