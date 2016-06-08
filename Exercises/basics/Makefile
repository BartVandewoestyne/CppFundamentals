CXXFLAGS = -Wall -Wextra

RECIPE = $(LINK.cc) $^ -o $@

all: hello_tass \
     echo_args \
     echo_name \
     echo_age

hello_tass: hello_tass.o
	$(RECIPE)

echo_args: echo_args.o
	$(RECIPE)

echo_name: echo_name.o
	$(RECIPE)

echo_age: echo_age.o
	$(RECIPE)

.PHONY: clean
clean:
	rm *.o
	-rm -f hello_tass echo_args echo_name echo_age
