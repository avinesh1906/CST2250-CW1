CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all: execute

execute : main.cpp events.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : test
test: testing

testing : testing.cpp events.o
	$(CXX) $(CXXFLAGS) -o $@ $^

events.o : events.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	$(RM) *.o
	$(RM) *.exe
