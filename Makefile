all: bin/geom2d.o bin/test_geom2d.o
	g++ bin/*.o -o bin/f2
	./bin/f2
#	echo $(test)

bin/geom2d.o: src/geom2d.cpp
	g++ -c src/geom2d.cpp -o $@

bin/test_geom2d.o: test/test_geom2d.cpp
	g++ -I src/ test/test_geom2d.cpp -c -o $@

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

