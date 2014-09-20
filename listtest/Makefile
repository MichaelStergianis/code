CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=listtest.c list.c debug.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=linetest

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLES) *.*~
