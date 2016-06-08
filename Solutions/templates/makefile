
CXXFLAGS = -Wall -Wextra

RECIPE = $(LINK.cc) $^ -o $@

default: smartpointer functions

../classes/Complex.o: ../classes/Complex.h ../classes/Complex.cpp
SmartPointer.hpp: ReferenceCounter.hpp
spmain.o: SmartPointer.hpp
smartpointer: CXXFLAGS += -DPRINT_WHAT_HAPPENS
smartpointer: spmain.o ../classes/Complex.o
	$(RECIPE)


functions: functions.o
	$(RECIPE)

clean:
	rm *.o
	rm smartpointer functions

make_run: default run

run:
	echo Running smartpointer
	./smartpointer
	echo
	echo Running functions
	./functions
	echo

