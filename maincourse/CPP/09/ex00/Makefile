TARGET = btc
CXX = g++
CXXFLAGS= -std=c++98 -g -Wall -Werror -Wextra
SRCS = main.cpp BitcoinExchange.cpp
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
	@./$(TARGET) input.txt

val: all
	@valgrind ./$(TARGET)

.PHONY: all
