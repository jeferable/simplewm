
#include "x11display.h"
#include "x11exception.h"

#include <X11/Xlib.h>

#include <iostream>

X11Display::X11Display()
{
    display = XOpenDisplay(NULL);
    if (display==NULL)
        throw X11Exception("Failed to open display");
}

X11Display::~X11Display()
{
    if (display != NULL) {
        XCloseDisplay(display);
    }
}

X11Window* X11Display::getDefaultRootWindow(){
    Window w = DefaultRootWindow(display);
    return new X11Window(w);
}

Display* X11Display::getDisplayId(){
    return display;
}
