CC=g++
CFLAGS=-c -std=c++11 -Wall
LDFLAGS=-lglog -lX11
SOURCES=main.cpp windowmanager.cpp x11abstractapplication.cpp x11display.cpp x11windowmanager.cpp x11window.cpp x11object.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=simplewm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o simplewm 
