CXX = g++
CXXFLAGS = -g -std=c++14

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: match.exe

match.exe: match_main.o match.o random_string.cpp
	$(CXX) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system

## Defie your own test* targets here and then add them to the all: target
## For example, if you implement a Caesar cipher, define a testCaesar.exe target
## and then add it to the dependencies of the all: target above. Do the 
## same for testDate.exe.

clean: 
	$(RM) *.o *.exe