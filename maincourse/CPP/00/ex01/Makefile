# Executable name
TARGET = PhoneBook
CXX = g++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all
