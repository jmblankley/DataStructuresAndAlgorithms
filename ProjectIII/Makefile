CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp WasteItem.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = WasteItem.hpp

.PHONY: all clean

all: run

run: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) run