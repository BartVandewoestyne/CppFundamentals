
CXXFLAGS = -Wall -Wextra -std=c++11

RECIPE = $(LINK.cc) $^ -o $@

default: shapes


shapes: shapes.o
	$(RECIPE)


clean:
	rm *.o
	rm shapes

make_run: default run

run:
	echo Running shapes
	./shapes
	echo

