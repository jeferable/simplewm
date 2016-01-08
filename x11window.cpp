#include "x11window.h"

X11Window::X11Window(Window id): id(id) {
}

X11Window::~X11Window() {
}

Window X11Window::getId() {
    return id;
}
