
CXXFLAGS = -Wall -Wextra

RECIPE = $(LINK.cc) $^ -o $@

default: hello_tass echo_args echo_name echo_age


hello_tass: hello_tass.o
	$(RECIPE)

echo_args: echo_args.o
	$(RECIPE)

echo_name: echo_name.o
	$(RECIPE)

echo_age: echo_age.o
	$(RECIPE)


clean:
	rm *.o
	rm hello_tass echo_args echo_name echo_age

make_run: default run

run:
	echo Running hello_tass
	./hello_tass
	echo
	echo Running echo_args
	./echo_args  arg1 arg2 another arg
	echo
	echo Not running echo_name, it needs user input
	echo Not running echo_arge, it needs user input