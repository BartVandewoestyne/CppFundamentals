
CXXFLAGS = -Wall -Wextra -g

RECIPE = $(LINK.cc) $^ -o $@

default: throw string_main complex_main

throw: throw.o
	$(RECIPE)

string_main: string_main.o TString.o
	$(RECIPE)

complex_main: complex_main.o Complex.o
	$(RECIPE)

# Complex.o complex_main.o : complex.h
# complex: Complex.o complex_main.o
# 	$(LINK.cc) $^ -o $@

clean:
	rm *.o
	rm throw string_main complex_main

make_run: default run

run:
	echo Running throw
	./throw
	echo
	echo Running string_main
	./string_main
	echo
	echo Running complex_main
	./complex_main
	echo
