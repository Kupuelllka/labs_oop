# Makefile for compiling geometry.cpp and unique_words.cpp

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20

# Source files and output files
SRC_GEOMETRY = list.cpp
OUT_GEOMETRY = list

SRC_UNIQUE_WORDS = priority_queue.cpp
OUT_UNIQUE_WORDS = priority_queue

# Default target
all: $(OUT_GEOMETRY) $(OUT_UNIQUE_WORDS)

# Build target for geometry
$(OUT_GEOMETRY): $(SRC_GEOMETRY)
	$(CXX) $(CXXFLAGS) $(SRC_GEOMETRY) -o $(OUT_GEOMETRY)

# Build target for unique_words
$(OUT_UNIQUE_WORDS): $(SRC_UNIQUE_WORDS)
	$(CXX) $(CXXFLAGS) $(SRC_UNIQUE_WORDS) -o $(OUT_UNIQUE_WORDS)

# Clean target
clean:
	rm -f $(OUT_GEOMETRY) $(OUT_UNIQUE_WORDS)

# Phony targets
.PHONY: all clean