CXX = g++
CXXFLAGS = -std=c++11 -Iheaders -Wall
SOURCES = src/main.cpp src/ecommerce.cpp src/person.cpp src/produk.cpp src/katalogManager.cpp
TARGET = ecommerce_system

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run