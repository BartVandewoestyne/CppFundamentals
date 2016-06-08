

CXXFLAGS = -Wall -Wextra -g

default:  complex

# initlist: initlist.o
# 	$(LINK.cc) $^ -o $@

Complex.o complex_main.o : complex.h
complex: Complex.o complex_main.o
	$(LINK.cc) $^ -o $@

clean:
	rm *.o
	rm complex

make_run: default run

run:
	echo Running complex
	./complex
	echo