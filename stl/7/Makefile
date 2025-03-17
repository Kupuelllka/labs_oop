
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20

# Source and output files
SRC = analysis.cpp
OUT = analysis

# Default target
all: $(OUT)

# Build target
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Clean target
clean:
	rm -f $(OUT)

# Phony targets
.PHONY: all clean