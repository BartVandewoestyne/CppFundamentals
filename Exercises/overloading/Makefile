CXXFLAGS = -Wall -Wextra

all: hello_tass \
     echo_args \
     echo_name \
     echo_age

hello_tass: hello_tass.o
	$(LINK.cc) $^ -o $@

echo_args: echo_args.o
	$(LINK.cc) $^ -o $@

echo_name: echo_name.o
	$(LINK.cc) $^ -o $@

echo_age: echo_age.o
	$(LINK.cc) $^ -o $@

.PHONY: clean
clean:
	-rm -f *.exe *.o
