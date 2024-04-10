# Executable name
TARGET = PhoneBook
CXX = g++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -g
SRCS = PhoneBook.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

test: all
	@printf "\n"
	./$(TARGET) "shhhhh... I think the students are asleep..."
	@printf "\n"
	./$(TARGET) Damnit " ! " "Sorry students, I thought this thing was off."
	@printf "\n"
	./$(TARGET) "This is a test"
	@printf "\n"
	./$(TARGET)
	@printf "\n"

.PHONY: all
