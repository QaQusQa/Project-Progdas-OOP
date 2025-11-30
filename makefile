CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = ecommerce
OBJS = main.o ecommerce.o person.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp ecommerce.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ecommerce.o: ecommerce.cpp ecommerce.h person.h
	$(CXX) $(CXXFLAGS) -c ecommerce.cpp

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c person.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean