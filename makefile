# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/resource_manager_test

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/ResourceManager.cpp \
          $(SRC_DIR)/CommandInvoker.cpp

# Header files
HEADERS = $(SRC_DIR)/ResourceManager.h \
          $(SRC_DIR)/CommandInvoker.h \
          $(SRC_DIR)/Command.h

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Create required directories
$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(BIN_DIR))

# Main target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean

# Run the program
run: $(TARGET)
	./$(TARGET)