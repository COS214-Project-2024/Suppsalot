# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = CitizenProgram

# Source files
SRCS = CitizenMain.cpp PrototypeCitizen.cpp CitizenCollection.cpp CitizenIterator.cpp HighClassCitizen.cpp MidClassCitizen.cpp LowClassCitizen.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target - builds the executable
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target - removes the compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run target - runs the program
run: $(TARGET)
	./$(TARGET)
