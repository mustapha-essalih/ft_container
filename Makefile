NAME = ft_container

CC = c++

C_FILES = main.cpp 

C_FLAGS = #-Wall -Wextra -Werror -std=c++98

O_FILES = $(C_FILES:.cpp=.o)

all : $(NAME)

%.o: %.cpp vector.hpp
	@${CC} ${C_FLAGS} -c $< -o $@


${NAME}: ${O_FILES} vector.hpp
	@${CC} ${C_FLAGS} ${O_FILES} -o ${NAME}

clean:
	@rm -f ${O_FILES}

fclean: clean
	@rm -f ${NAME}

re: fclean all