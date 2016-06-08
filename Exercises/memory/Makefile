CXXFLAGS = -Wall -Wextra

all: string_example

TString.o: TString.cpp TString.h
	$(CXX) -c $^

main.o: main.cpp TString.h
	$(CXX) -c $^

string_example: main.o TString.o
	$(LINK.cc) $^ -o $@

.PHONY: clean
clean:
	-rm -f *.exe *.o *.gch
