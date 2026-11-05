CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall

SRCS = main.cpp funkcijos.cpp studentas.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = programa.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)