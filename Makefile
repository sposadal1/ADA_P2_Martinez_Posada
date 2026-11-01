CXX = g++
CXXFLAGS = -O2 -Wall -Wextra -std=c++11 -Iinclude

SRCS = src/utils.cpp src/operaciones.cpp src/karatsuba.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f src/*.o $(TARGET)