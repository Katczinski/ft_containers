HEADER		= includes/Vector/vector.hpp\
			includes/Vector/vector_iterator.hpp\
			includes/Map/map.hpp\
			includes/Map/tree.hpp\
			includes/Stack/stack.hpp\
			includes/Map/rb_tree_iterator.hpp\
			includes/ft_utils.hpp\

INC			= -Iincludes -Iincludes/Vector -Iincludes/Map -Iincludes/Stack

FLAGS		= -std=c++98 -Wall -Wextra -Werror
TEST_FLAGS	= -std=c++98 -g -Wall -Wextra -Werror

CC			= clang++

all:		map vector stack


map:		$(HEADER) map_test.cpp
			$(CC) $(TEST_FLAGS) $(INC) map_test.cpp -o map
			
vector:		$(HEADER) vector_test.cpp
			$(CC) $(TEST_FLAGS) $(INC) vector_test.cpp -o vector

stack:		$(HEADER) stack_test.cpp
			$(CC) $(TEST_FLAGS) $(INC) stack_test.cpp -o stack

%.o:		%.cpp $(HEADER)
			$(CC) -g $(FLAGS) $(INC) -c $< -o $@

clean:

fclean:		clean
			rm -rf map
			rm -rf vector
			rm -rf stack


re:			fclean all

.PHONY:		all clean fclean re