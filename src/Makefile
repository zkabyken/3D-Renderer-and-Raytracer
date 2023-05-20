# Compiler settings
CXX := clang++       # C++ compiler
CXXFLAGS := -std=c++20 -O3  # Compiler flags

# Source files
SRCS := main.cpp
HDRS := color.hpp sphere.hpp hittable_list.hpp mathfuncs.hpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := raytracer

.PHONY: all clean

# Default rule
all: $(TARGET)

# Rule to compile source files into object files
$(OBJS): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)