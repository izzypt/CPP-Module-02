NAME = Fixed

SRCS = main.cpp Fixed.cpp operators.cpp

CC = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address -g

RM = rm -rf

all : $(NAME)

$(NAME): $(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
		$(RM) $(NAME)

fclean: clean
			rm -f $(NAME)

re: fclean all