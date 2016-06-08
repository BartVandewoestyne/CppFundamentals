
CXXFLAGS = -Wall -Wextra -std=c++11
LDFLAGS =  -lcppunit

RECIPE = $(LINK.cc) $^ -o $@ 

default: TString_tests SmartPointer_tests Complex_tests TestCaller_tests Detokenizer_tests

../memory/TString.o : ../memory/TString.h ../memory/TString.cpp
TStringTests.o: TStringTests.hpp
TString_tests: CXXFLAGS += -DSUITE_CLASS=1
TString_tests.o : test.cpp
	$(COMPILE.cc)  $^ -o $@
TString_tests: TString_tests.o ../memory/TString.o TStringTests.o
	$(RECIPE)

# hello: hello.o
# 	$(RECIPE)

../classes/Complex.o : ../classes/Complex.h ../classes/Complex.cpp

SmartPointerTests.o: SmartPointerTests.hpp ../templates/SmartPointer.hpp ../classes/Complex.o
SmartPointer_tests: CXXFLAGS += -DSUITE_CLASS=2
SmartPointer_tests.o : test.cpp
	$(COMPILE.cc)  $^ -o $@
SmartPointer_tests: SmartPointer_tests.o SmartPointerTests.o ../classes/Complex.o
	$(RECIPE)

ComplexTests.o: ComplexTests.hpp TestCaller.hpp
Complex_tests: CXXFLAGS += -DSUITE_CLASS=3
Complex_tests.o: test.cpp
	$(COMPILE.cc)  $^ -o $@
Complex_tests: Complex_tests.o ComplexTests.o ../classes/Complex.o
	$(RECIPE)

Detokenizer.o: Detokenizer.hpp
DetokenizerTests.o: DetokenizerTests.hpp Detokenizer.hpp
Detokenizer_tests: CXXFLAGS += -DSUITE_CLASS=5
Detokenizer_tests.o: test.cpp
	$(COMPILE.cc)  $^ -o $@
Detokenizer_tests: Detokenizer_tests.o DetokenizerTests.o Detokenizer.o
	$(RECIPE)

TestCallerTests.o: TestCallerTests.hpp TestCaller.hpp
TestCaller_tests: CXXFLAGS += -DSUITE_CLASS=4
TestCaller_tests.o: test.cpp
	$(COMPILE.cc)  $^ -o $@
TestCaller_tests: TestCaller_tests.o TestCallerTests.o
	$(RECIPE)



clean:
	rm *.o
	rm TString_tests SmartPointer_tests Complex_tests TestCaller_tests Detokenizer_tests

make_run: default run

run:
	echo Running TString_tests
	./TString_tests
	echo
	echo Running SmartPointer_tests
	./SmartPointer_tests
	echo
	echo Running Complex_tests
	./Complex_tests
	echo
	echo Running Detokenizer_tests
	./Detokenizer_tests
	echo
	echo Running TestCaller_tests
	./TestCaller_tests
	echo

