.PHONY: debug release test clean

CXXFLAGS := -Werror -Wpedantic -Wall -std=c++17 -O0 -g -I src/

test: bin/geom2d.o bin/struct2d.o bin/math2d.o bin/test_geom2d.o bin/test_struct2d.o bin/test_math2d.o
	$(CXX) $(CXXFLAGS) $^ -o bin/f2
	./bin/f2

# If bin/ doesn't exist on start, it will be created by the first rule in the queue.
# If first rule is skipped, then folder should already exist.
bin/geom2d.o: src/geom2d.cpp src/geom2d.hpp
	mkdir -p bin/
	$(CXX) $(CXXFLAGS) $< -c -o $@

bin/struct2d.o: src/struct2d.cpp src/struct2d.hpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

bin/math2d.o: src/math2d.cpp src/math2d.hpp
	$(CXX) $(CXXFLAGS) $< -c -o $@


bin/test_geom2d.o: test/test_geom2d.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

bin/test_struct2d.o: test/test_struct2d.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

bin/test_math2d.o: test/test_math2d.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -rf bin/
