#CXX=g++-4.8
CXXFLAGS = -Wall -Wextra

RECIPE = $(LINK.cc) $^ -o $@

default: string vector vector_capacity areacodes areacodes_reverse

string: string.o
	$(RECIPE)

vector_capacity: vector_capacity.o
	$(RECIPE)

vector: vector.o
	$(RECIPE)


areacodes: areacodes.o
	$(RECIPE)

areacodes_reverse: areacodes_reverse.o
	$(RECIPE)


clean:
	rm *.o
	rm string vector vector_capacity areacodes areacodes_reverse

make_run: default run

run:
	echo Running string
	./string
	echo
	echo Running vector
	./vector 6 67 42 44 666 bad
	echo
	echo Running vector_capacity
	./vector_capacity
	echo
	echo Running areacodes 
	./areacodes zipcodes_alpha_nl.csv 8400 8500
	echo
	echo Running areacodes_reverse 
	./areacodes_reverse zipcodes_alpha_nl.csv sinterKlaas
	./areacodes_reverse zipcodes_alpha_nl.csv Gent
	echo
