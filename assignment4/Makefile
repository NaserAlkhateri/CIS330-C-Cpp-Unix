CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

tests: reversi.exe

reversi.exe: main.o reversi.o
	$(CXX) $(CXXFLAGS) -o $@ $^

memcheckReversi.exe: reversi.exe
	valgrind --leak-check=yes --track-origins=yes ./reversi.exe

clean:
	$(RM) -r *.o *.exe*
