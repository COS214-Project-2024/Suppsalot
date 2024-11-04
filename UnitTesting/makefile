# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -I/usr/local/include

# Directories
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/building_simulator
TEST_TARGET = $(BIN_DIR)/tests
DOCTEST_TARGET = $(BIN_DIR)/doctest_runner

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/BuildingFactory.cpp \
          $(SRC_DIR)/ResidentialBuilding.cpp \
          $(SRC_DIR)/IndustrialBuilding.cpp \
          $(SRC_DIR)/CommercialBuilding.cpp \
          $(SRC_DIR)/LandmarkBuilding.cpp \
          $(SRC_DIR)/ResourceManager.cpp \
          $(SRC_DIR)/Road.cpp \
          $(SRC_DIR)/NotOperational.cpp \
          $(SRC_DIR)/Bad.cpp \
          $(SRC_DIR)/Okay.cpp \
          $(SRC_DIR)/Good.cpp \
          $(SRC_DIR)/Excellent.cpp \
          $(SRC_DIR)/TrainSystem.cpp \
          $(SRC_DIR)/Star1.cpp \
          $(SRC_DIR)/Star2.cpp \
          $(SRC_DIR)/Star3.cpp \
          $(SRC_DIR)/Star4.cpp \
          $(SRC_DIR)/Star5.cpp \
          $(SRC_DIR)/TransportObserver.cpp \
          $(SRC_DIR)/PublicTransit.cpp \
          $(SRC_DIR)/NoUberAndBolt.cpp \
          $(SRC_DIR)/Uber.cpp \
          $(SRC_DIR)/Bolt.cpp \
          $(SRC_DIR)/UberAndBolt.cpp \
          $(SRC_DIR)/CitySimulation.cpp \
          $(SRC_DIR)/TaxContext.cpp \
          $(SRC_DIR)/ProgressiveTax.cpp \
          $(SRC_DIR)/FlatTax.cpp \
          $(SRC_DIR)/RegressiveTax.cpp \
          $(SRC_DIR)/TaxHistoryManager.cpp \
          $(SRC_DIR)/PrototypeCitizen.cpp \
          $(SRC_DIR)/CitizenCollection.cpp \
          $(SRC_DIR)/CitizenIterator.cpp \
          $(SRC_DIR)/HighClassCitizen.cpp \
          $(SRC_DIR)/MidClassCitizen.cpp \
          $(SRC_DIR)/LowClassCitizen.cpp \
          $(SRC_DIR)/CitizenStatistics.cpp \
          $(SRC_DIR)/CitizensManager.cpp

# Header files
HEADERS = $(SRC_DIR)/BuildingFactory.h \
          $(SRC_DIR)/ResidentialBuilding.h \
          $(SRC_DIR)/IndustrialBuilding.h \
          $(SRC_DIR)/LandmarkBuilding.h \
          $(SRC_DIR)/CommercialBuilding.h \
          $(SRC_DIR)/ResourceManager.h \
          $(SRC_DIR)/BuildingStatistics.h \
          $(SRC_DIR)/ResourceObserver.h \
          $(SRC_DIR)/CitizensManager.h

# Test source files
TEST_SOURCES = $(SRC_DIR)/TaxManagerTest.cpp  # Add your test source files here

# Doctest source files
DOCTEST_SOURCES = $(SRC_DIR)/TestableCitizensManager.cpp \
#                  $(SRC_DIR)/TestableResourceManager.cpp  # Add your doctest source files here

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJECTS = $(TEST_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DOCTEST_OBJECTS = $(DOCTEST_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Create required directories (shell commands)
$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(BIN_DIR))

# Main target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Test target
$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(OBJECTS) -o $(TEST_TARGET) -lgtest -lgtest_main -pthread

# Doctest target
$(DOCTEST_TARGET): $(DOCTEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(DOCTEST_OBJECTS) $(OBJECTS) -o $(DOCTEST_TARGET)

# Compilation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean test doctest run valgrind

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Run doctest tests
doctest: $(DOCTEST_TARGET)
	./$(DOCTEST_TARGET)