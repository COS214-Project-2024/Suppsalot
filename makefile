# # Compiler settings
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra

# # Directories
# SRC_DIR = .
# BUILD_DIR = build
# BIN_DIR = bin

# # Target executable
# TARGET = $(BIN_DIR)/resource_manager_test

# # Source files
# SOURCES = $(SRC_DIR)/main.cpp \
#           $(SRC_DIR)/ResourceManager.cpp \
#           $(SRC_DIR)/CommandInvoker.cpp \
# 		  $(SRC_DIR)/BuildingFactory.cpp \
# 		  $(SRC_DIR)/ResidentialBuilding.cpp 

# # Header files
# HEADERS = $(SRC_DIR)/ResourceManager.h \
#           $(SRC_DIR)/CommandInvoker.h \
#           $(SRC_DIR)/Command.h \
# 		  $(SRC_DIR)/BuildingFactory.h \
# 		  $(SRC_DIR)/ResidentialBuilding.h 

# # Object files
# OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# # Create required directories
# $(shell mkdir -p $(BUILD_DIR))
# $(shell mkdir -p $(BIN_DIR))

# # Main target
# all: $(TARGET)

# # Linking
# $(TARGET): $(OBJECTS)
# 	$(CXX) $(OBJECTS) -o $(TARGET)

# # Compilation
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean build files
# clean:
# 	rm -rf $(BUILD_DIR) $(BIN_DIR)

# # Phony targets
# .PHONY: all clean

# # Run the program
# run: $(TARGET)
# 	./$(TARGET)

# Compiler settings
# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/building_simulator

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/BuildingFactory.cpp \
          $(SRC_DIR)/ResidentialBuilding.cpp \
          $(SRC_DIR)/IndustrialBuilding.cpp \
          $(SRC_DIR)/LandmarkBuilding.cpp \
          $(SRC_DIR)/ResourceManager.cpp

# Header files
HEADERS = $(SRC_DIR)/BuildingFactory.h \
          $(SRC_DIR)/ResidentialBuilding.h \
          $(SRC_DIR)/IndustrialBuilding.h \
          $(SRC_DIR)/LandmarkBuilding.h \
          $(SRC_DIR)/ResourceManager.h \
          $(SRC_DIR)/ResourceObserver.h

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Create required directories (shell commands)
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

# Run with Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

