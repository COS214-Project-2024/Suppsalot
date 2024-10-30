CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g  # Added -g for debug symbols
TARGET = resource_management
SRCS = main.cpp ResourceManager.cpp
HEADERS = ResourceManager.h ResourceObserver.h

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean run valgrind

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		./$(TARGET)