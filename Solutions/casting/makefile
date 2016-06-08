

CXXFLAGS = -Wall -Wextra

RECIPE = $(LINK.cc) $^ -o $@

default: lexical_cast lexical_complex

lexical_cast: lexical_cast.o
	$(RECIPE)


../classes/Complex.o: ../classes/Complex.h ../classes/Complex.cpp
lexical_complex: lexical_complex.o ../classes/Complex.o
	$(RECIPE)


clean:
	rm *.o
	rm lexical_cast lexical_complex

make_run: default run

run:
	echo Running lexical_cast
	./lexical_cast
	echo
	echo Running lexical_complex
	./lexical_complex
	echo

