TARGET = a.out
CXX = g++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	@rm -f $(OBJS) $(TARGET)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

run: all
	@./$(TARGET)

.PHONY: all
