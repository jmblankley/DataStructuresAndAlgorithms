CXX = g++
CXXFLAGS = -std=c++11
TARGET = stacker

all: $(TARGET)

$(TARGET): main.o Stack.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

Stack.o: Stack.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
