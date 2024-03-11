CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Node.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Node.hpp

.PHONY: all clean

all: run

run: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) run