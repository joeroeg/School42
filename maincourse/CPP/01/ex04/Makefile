TARGET = a.out
CXX = g++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Sed.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) file.replace

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all
