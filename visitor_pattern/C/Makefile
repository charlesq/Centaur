TARGET := test
G++ := g++ -g -gdwarf-2  -O0 -std=c++11 -std=gnu++11
SRC := src
ALGORITHMS := $(SRC)/heap_sort.cpp $(SRC)/quick_sort.cpp $(SRC)/merge_sort.cpp \
              $(SRC)/radix_sort.cpp $(SRC)/bubble_sort.cpp $(SRC)/insert_sort.cpp\
INC := . 
BIN := bin
OBJS := $(BIN)/heap_sort.o $(BIN)/quick_sort.o $(BIN)/merge_sort.o $(BIN)/radix_sort.o \
        $(BIN)/bubble_sort.o $(BIN)/insert_sort.o  $(BIN)/int_visitor.o $(BIN)/pair_visitor.o

$(BIN)/%.o: $(SRC)/%.cpp
	$(G++) -c -I. -o $@ $< 
all: test $(OBJS)
 
.PHONY: test 
test:
	make -p bin;

clean:
	rm  bin/*

