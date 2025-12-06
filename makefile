CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = tokoOnline
OBJS = main.o tokoOnline.o pengguna.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp tokoOnline.h
	$(CXX) $(CXXFLAGS) -c main.cpp

tokoOnline.o: tokoOnline.cpp tokoOnline.h pengguna.h
	$(CXX) $(CXXFLAGS) -c tokoOnline.cpp

pengguna.o: pengguna.cpp pengguna.h
	$(CXX) $(CXXFLAGS) -c pengguna.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean