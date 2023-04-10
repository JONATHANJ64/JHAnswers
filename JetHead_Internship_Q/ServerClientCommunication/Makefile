CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

.PHONY: all clean

all: Server Client

Server: Server.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Client: Client.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f server Client
