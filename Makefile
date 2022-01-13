CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all: execute

execute : main.cpp events.o live.o standUp.o film.o
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : test
test: testing

testing : testing.cpp events.o live.o standUp.o film.o
	$(CXX) $(CXXFLAGS) -o $@ $^

live.o : live.cpp 
	$(CXX) $(CXXFLAGS) -c $^

standUp.o : standUp.cpp 
	$(CXX) $(CXXFLAGS) -c $^

film.o : film.cpp 
	$(CXX) $(CXXFLAGS) -c $^

events.o : events.cpp 
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	$(RM) *.o
	$(RM) execute, testing
