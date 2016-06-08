
CXXFLAGS = -Wall -Wextra -std=c++11 

RECIPE = $(LINK.cc) $^ -o $@

default: funcpointer

funcpointer: funcpointer.o
	$(RECIPE)

clean:
	rm *.o
	rm funcpointer

make_run: default run

run:
	echo Running funcpointer
	./funcpointer
	echo

