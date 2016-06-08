
CXXFLAGS = -Wall -Wextra

default: which plus minus stream

RECIPE = $(LINK.cc) $^ -o $@

# output: output.o
# 	$(LINK.cc) $^ -o $@

which: which.o
	$(RECIPE)

plus: plus.o
	$(RECIPE)

minus: minus.o
	$(RECIPE)

stream: stream.o
	$(RECIPE)


clean:
	rm *.o
	rm which plus minus stream

make_run: default run

run:
	echo Running which
	./which
	echo
	echo Running plus
	./plus
	echo
	echo Running minus
	./minus
	echo 
	echo Running stream
	./stream
	echo