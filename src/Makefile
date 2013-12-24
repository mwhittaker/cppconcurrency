CXX      = g++
RM       = rm
CPPFLAGS = -Wall -Wextra -Werror -g -O2 -Wall -pedantic -std=c++11 -pthread
SRCS     = $(wildcard *.cpp) 

all: $(SRCS:.cpp=)

.cpp:
	$(CXX) $(CPPFLAGS) $< -o $@.out

clean:
	$(RM) *.out
