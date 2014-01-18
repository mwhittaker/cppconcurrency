CXX      = g++
RM       = rm
CPPFLAGS = -Wall -Wextra -Werror -g -O2 -Wall -pedantic -std=c++11 -pthread
SRCS     = $(wildcard *.cpp) 
OBJS     = $(wildcard ../src/*.cpp)
HEADERS  = $(wildcard ../src/*.h) $(wildcard ../src/*.hpp)
INC      = -I../src
LIBS     = -lboost_system 

all: $(SRCS:.cpp=.out)

%.out: %.cpp $(OBJS) $(HEADERS)
	$(CXX) $< -o $@ $(CPPFLAGS) $(INC) $(OBJS) $(LIBS) 

clean:
	$(RM) *.out
