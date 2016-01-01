CC=g++
CFLAGS=-c -Wall -lglog
LDFLAGS=
SOURCES=main.cpp windowmanager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=simplewm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *o
