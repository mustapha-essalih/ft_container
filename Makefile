NAME = ft_container

CC = c++

C_FILES = main.cpp 

H_FILES = vector.hpp iterator.hpp  iterator_traits.hpp reverse_iterator.hpp std_mechanism.hpp

C_FLAGS = #-Wall -Wextra -Werror -std=c++98

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