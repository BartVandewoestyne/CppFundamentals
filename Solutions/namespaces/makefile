
CXXFLAGS = -Wall -Wextra -std=c++11 

RECIPE = $(LINK.cc) $^ -o $@

default: tass_cout

#tass_cout : CXXFLAGS += -DUSE_MY_COUT
tass_cout_main.o cout.o : cout.h
tass_cout: tass_cout_main.o cout.o
	$(RECIPE)

# tass_cout_std: clean 
# tass_cout_std : tass_cout_main.o cout.o
# 	$(RECIPE)


clean:
	rm *.o
	rm tass_cout

make_run: default run

run:
	echo Running tass_cout
	./tass_cout
	echo

# echo Running tass_cout_std
# ./tass_cout_std
# echo
