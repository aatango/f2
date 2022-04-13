all: bin/geom2d.o bin/test.o bin/main.o
	g++ bin/*.o -o bin/f2
	./bin/f2
#	echo $(test)

bin/geom2d.o: src/geom2d.cpp
	g++ -c src/geom2d.cpp -o $@

bin/test.o: test/tests.cpp
	g++ -I src/ test/tests.cpp -c -o $@

bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o $@
	
# From Kakoune's Makefile
debug ?= y

ifeq ($(debug), y)
	CXXFLAGS += -O0
	suffix := .debug
else
	ifeq ($(debug), n)
		CXXFLAGS += -O3
		suffix := .release
	else
		$(error Unkown debug status)
	endif
endif

CXXFLAGS += -Werror -pedantic -Wall -std=c++20

# test:
# debug:
# release:

