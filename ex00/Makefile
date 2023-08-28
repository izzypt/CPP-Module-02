NAME = Fixed

SRCS = main.cpp Fixed.cpp

CC = c++

FLAGS = -g -std=c++98 -Wall -Werror -Wextra -fsanitize=address

RM = rm -rf

all : $(NAME)

$(NAME): $(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
		$(RM) $(NAME)

fclean: clean
			rm -f $(NAME)

re: fclean all