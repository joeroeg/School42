TARGET = PmergeMe
CXX = g++
CXXFLAGS= -std=c++98 -g -Wall -Werror -Wextra
SRCS = main.cpp PmergeMe.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	@rm -f $(OBJS) $(TARGET)

fclean: clean
	@rm -f $(TARGET) Shrubbery_form

re: fclean all

run: all
	@./$(TARGET) 5 4 3 2 1

val: all
	@valgrind ./$(TARGET) `jot -r 3000 1 3000 | tr '\n' ' '`

test: all
	@time ./$(TARGET) `jot -r 3000 1 3000 | tr '\n' ' '`

test2: all
	@time ./$(TARGET) `jot -r 9000 1 9000 | tr '\n' ' '`

.PHONY: all
