CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

OBJS = main.o CityStats.o StatsMemento.o CityGrowthOg.o StatsCaretaker.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp CityStats.h StatsMemento.h CityGrowthOg.h StatsCaretaker.h
	$(CXX) $(CXXFLAGS) -c main.cpp

CityStats.o: CityStats.cpp CityStats.h
	$(CXX) $(CXXFLAGS) -c CityStats.cpp

StatsMemento.o: StatsMemento.cpp StatsMemento.h CityStats.h
	$(CXX) $(CXXFLAGS) -c StatsMemento.cpp

CityGrowthOg.o: CityGrowthOg.cpp CityGrowthOg.h CityStats.h StatsMemento.h
	$(CXX) $(CXXFLAGS) -c CityGrowthOg.cpp

StatsCaretaker.o: StatsCaretaker.cpp StatsCaretaker.h StatsMemento.h
	$(CXX) $(CXXFLAGS) -c StatsCaretaker.cpp

clean:
	rm -f *.o main
