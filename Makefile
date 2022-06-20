CXXFLAGS = -Wall -pedantic -std=c++17

HEADERS = $(wildcard src/*.h src/*/*.h src/*/*/*.h)
SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)

.PHONY: all
all: compile doc

.PHONY: run
run: compile
	./popovle1

.PHONY: compile
compile: popovle1

popovle1: build/main
	cp $< $@

build/main: $(OBJECTS)
	mkdir -p $(@D)
	g++ $^ -o $@

build/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ $(CXXFLAGS) $< -c -o $@

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile
	touch doc/index.html
	echo '<meta http-equiv="REFRESH" content="0;URL=html/index.html">' > doc/index.html

.PHONY: clean
clean:
	rm -rf popovle1 build/ debug/ doc/ 2>/dev/null

deps:
	g++ -MM src/*.cpp src/*/*.cpp src/*/*/*.cpp > Makefile.d
-include Makefile.d