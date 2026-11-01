CXX = g++
CXXFLAGS = -O2 -Iinclude -Wall

SRCS = src/utils.cpp src/operaciones.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /f /q src\*.o $(TARGET) 2>nul || rm -f src/*.o $(TARGET)

.PHONY: all clean