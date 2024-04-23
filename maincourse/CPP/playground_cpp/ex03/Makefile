TARGET = a.out
CXX = g++
CXXFLAGS= -std=c++98 -g #-Wall -Werror -Wextra
SRCS = main.cpp AMateria.cpp #Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	@rm -f $(OBJS) $(TARGET)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

run: all
	@./$(TARGET)

.PHONY: all
