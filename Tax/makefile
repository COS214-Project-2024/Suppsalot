# Makefile

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Source Files
SRCS = main.cpp \
       CitySimulation.cpp \
       TaxContext.cpp \
       ProgressiveTax.cpp \
       FlatTax.cpp \
       RegressiveTax.cpp \
       TaxHistoryManager.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Executable Name
EXEC = city_simulation

# Default Target
all: $(EXEC)

# Build Executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony Targets
.PHONY: all clean
