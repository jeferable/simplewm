
#include "x11display.h"

#include <exception>

X11Display::X11Display(const char* str)
{
    display = XOpenDisplay(str);
    if (display == nullptr)
        throw std::exception("Failed to open display");
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

X11Display* X11Display::makeDisplay(const std::string displayStr){
    const char* display_c_str = displayStr.empty() ? NULL : displayStr.c_str();
    return new X11Display(display_c_str);
}

X11Display* X11Display::makeDisplay(){
    return makeDisplay(std::string());
}
