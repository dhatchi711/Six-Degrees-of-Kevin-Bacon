CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = graph.o sixdegrees.o

sixdegrees: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean: 
	rm -f *.o sixdegrees
$(OBJECTS): graph.h
