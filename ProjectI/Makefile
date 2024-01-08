CXX = g++
CXXFLAGS = -std=c++11
TARGET = project1

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
