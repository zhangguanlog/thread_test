TARGET = result
CPP = g++
CXXFLAGS = -g -Wall 
SRC = multi_thread_test.cpp

$(TARGET):multi_thread_test.o
	$(CPP) $(CXXFLAGS) multi_thread_test.o -lpthread -o $(TARGET)

multi_thread_test.o:multi_thread_test.cpp
	$(CPP) -c multi_thread_test.cpp -o multi_thread_test.o

clean:
	rm -rf $(TARGET) multi_thread_test.o

