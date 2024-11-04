# Makefile

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

# Source Files
SRCS = main.cpp \
       Road.cpp \
       NotOperational.cpp \
       Bad.cpp \
       Okay.cpp \
       Good.cpp \
       Excellent.cpp \
       TrainSystem.cpp \
       Star1.cpp \
       Star2.cpp \
       Star3.cpp \
       Star4.cpp \
       Star5.cpp \
       TransportObserver.cpp \
       PublicTransit.cpp \
       NoUberAndBolt.cpp \
       Uber.cpp \
       Bolt.cpp \
       UberAndBolt.cpp \
       CitySimulation.cpp \
       TaxContext.cpp \
       ProgressiveTax.cpp \
       FlatTax.cpp \
       RegressiveTax.cpp \
       TaxHistoryManager.cpp \
       BuildingFactory.cpp \
       ResidentialBuilding.cpp \
       IndustrialBuilding.cpp \
       CommercialBuilding.cpp \
       LandmarkBuilding.cpp \
       ResourceManager.cpp

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
