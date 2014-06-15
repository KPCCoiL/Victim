PROGRAM = runvtm
TARGET = runvtm.cpp
CXX := g++
all: runvtm.cpp
	$(CXX) $(TARGET) -std=c++11 -o $(PROGRAM)
