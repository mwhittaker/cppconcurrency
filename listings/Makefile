CXX      = g++
RM       = rm
CPPFLAGS = -Wall -Wextra -Werror -g -O2 -Wall -pedantic -std=c++11 -pthread
SRCS     = $(wildcard *.cpp) 
OBJS     = $(wildcard ../src/*.cpp)
INC      = -I../src
LIBS     = -lboost_system 

all: $(SRCS:.cpp=)

.cpp: $(OBJS)
	$(CXX) $< -o $@.out $(CPPFLAGS) $(INC) $(OBJS) $(LIBS) 
clean:
	$(RM) *.out
