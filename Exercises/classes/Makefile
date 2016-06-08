CXXFLAGS = -Wall -Wextra

all: complex_example

Complex.o: Complex.cpp Complex.h
	$(CXX) -c $^

main.o: main.cpp
	$(CXX) -c $^

complex_example: main.o Complex.o
	$(LINK.cc) $^ -o $@

.PHONY: clean
clean:
	-rm -f *.exe *.o *.gch
