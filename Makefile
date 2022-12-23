NAME = ft_container

CC = c++

C_FILES = main.cpp 

H_FILES =  avl.hpp map.hpp iterator.hpp type_traits.hpp



C_FLAGS = -std=c++98#-Wall -Wextra -Werror -std=c++98

O_FILES = $(C_FILES:.cpp=.o)

all : $(NAME)

%.o: %.cpp ${H_FILES}
	@${CC} ${C_FLAGS} -c $< -o $@


${NAME}: ${O_FILES} ${H_FILES}
	@${CC} ${C_FLAGS} ${O_FILES} -o ${NAME}

clean:
	@rm -f ${O_FILES}

fclean: clean
	@rm -f ${NAME}

re: fclean all