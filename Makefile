# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Executable name
TARGET = CitizenProgram

# Source files
SRCS = CitizenMain.cpp \
       PrototypeCitizen.cpp \
       CitizenCollection.cpp \
       CitizenIterator.cpp \
       HighClassCitizen.cpp \
       MidClassCitizen.cpp \
       LowClassCitizen.cpp \
       CitizenStatistics.cpp \
       ResourceManager.cpp \

# Header files (for dependency tracking)
HEADERS = BuildingStatistics.h \
          ResourceObserver.h \
          PrototypeCitizen.h \
          CitizenCollection.h \
          CitizenIterator.h \
          HighClassCitizen.h \
          MidClassCitizen.h \
          LowClassCitizen.h \
          CitizenStatistics.h \
          ResourceManager.h \

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Default target - builds the executable
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
# Added dependency on all headers to ensure recompilation when any header changes
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target - removes the compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Run target - runs the program
run: $(TARGET)
	./$(TARGET)

# Header-only dependency checking
$(OBJS): $(HEADERS)

.PHONY: all clean run