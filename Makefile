CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all: execute

execute : main.cpp events.o
	$(CXX) $(CXXFLAGS) -o $@ $^

events.o : events.cpp events.h
	$(CXX) $(CXXFLAGS) -c $<

	
.PHONY : clean
clean :
	$(RM) *.o
	$(RM) execute