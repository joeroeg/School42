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
	@time ./$(TARGET)

val: all
	@valgrind ./$(TARGET)

test: all
	@time ./$(TARGET) `jot -r 3000 1 3000 | tr '\n' ' '` > result

.PHONY: all
