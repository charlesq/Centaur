TARGET := test
test: main.cpp Node.hpp Singly_linked_list.hpp
	g++ -g  -O0 $(GLIBH)  $^   -std=c++11 -std=gnu++11 -I .  -gdwarf-2  -o $(TARGET)
all: test

clean:
	rm test;
