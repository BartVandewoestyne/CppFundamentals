

CXXFLAGS = -Wall -Wextra

RECIPE = 	$(LINK.cc) $^ -o $@

default:  lifetime string

lifetime: lifetime.o
	$(RECIPE)

TString.o string_main.o: TString.h
string: TString.o string_main.o
	$(RECIPE)

clean:
	rm *.o
	rm lifetime string

make_run: default run

run:
	echo Running lifetime
	./lifetime
	echo
	echo Running string
	./string
	echo