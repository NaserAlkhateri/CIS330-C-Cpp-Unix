SOURCES = reversi.cpp
HEADERS = reversi.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = g++
CFLAGS = -std=c14 -g -fPIC

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

tests: reversi.exe

reversi.exe: reversi.o
	$(CC) $(CFLAGS) -o $@ $^

memcheckReversi.exe: reversi.exe
	valgrind --leak-check=yes --track-origins=yes ./reversi.exe

clean:
	$(RM) $(OBJECTS) *.exe
	$(RM) $(OBJECTS) *~
