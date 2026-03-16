CXX = g++
CXXFLAGS = -O3 -std=c++20
SRC = $(wildcard src/*.cpp)
BINS = $(patsubst src/%.cpp, bin/%, $(SRC))
all: $(BINS)
bin/%: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
clean:
	rm -f bin/*
