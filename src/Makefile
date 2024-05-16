# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Source files
SRCS := $(wildcard *.cpp)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Binary output
TARGET := ecosystem.bin

# Directories
SRCDIR := .
INPUTDIR := ../input

# Targets
.PHONY: all clean sample

# Default target
all: $(TARGET)

# Compile target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to compile each source file to object files
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Sample target to run the compiled binary with input files
sample: $(TARGET)
	./$(TARGET) $(INPUTDIR)/map.txt $(INPUTDIR)/species.txt
