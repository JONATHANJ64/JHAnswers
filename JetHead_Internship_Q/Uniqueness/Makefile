CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

all: uniqueness

uniqueness: uniqueness.o
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f uniqueness uniqueness.o