NAME = ft_container

CC = c++

C_FILES = main.cpp 

H_FILES =  ./map/map.hpp ./map/red_black_tree.hpp ./map/iterator.hpp  ./utils/reverse_iterator.hpp  ./utils/type_traits.hpp ./utils/iterator_traits.hpp \
			./vector/vector.hpp ./vector/vector_iterator.hpp ./stack/stack.hpp ./set/set.hpp




C_FLAGS =  -Wall -Wextra -Werror -std=c++98

O_FILES = $(C_FILES:.cpp=.o)

all : $(NAME)

%.o: %.cpp ${C_FILES} ${H_FILES}
	@${CC} ${C_FLAGS} -c $< -o $@


${NAME}: ${O_FILES} ${H_FILES}
	@${CC} ${C_FLAGS} ${O_FILES} -o ${NAME}

clean:
	@rm -f ${O_FILES}

fclean: clean
	@rm -f ${NAME}

re: fclean all