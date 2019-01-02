CC=g++
CFLAGS=-c -std=c++11 -Wall
LDFLAGS=-lglog -lX11
SOURCES=main.cpp windowmanager.cpp x11windowmanager.cpp x11application.cpp x11object.cpp x11window.cpp x11display.cpp x11event.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=simplewm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o build/$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
.PHONY : clean
clean:
	rm *.o build/simplewm 
