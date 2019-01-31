SOURCES = reversi.c
HEADERS = reversi.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c11 -g -fPIC

%.o: %.c
	$(CC) -c $(CFLAGS) $<

tests: reversi.exe

reversi.exe: reversi.o
	$(CC) $(CFLAGS) -o $@ $^

memcheckReversi.exe: reversi.exe
	valgrind --leak-check=yes --track-origins=yes ./reversi.exe

clean:
	$(RM) $(OBJECTS) *.exe
	$(RM) $(OBJECTS) *~
