TARGET := test
test: main.cpp node.hpp skip_list.hpp
	g++ -g  -O0  $^   -std=c++11 -std=gnu++11 -I/usr/include/mysql  -gdwarf-2 -pthread  -o $(TARGET)
all: test


