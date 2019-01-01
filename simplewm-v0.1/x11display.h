#ifndef X11DISPLAY_H
#define X11DISPLAY_H

#include "x11window.h"

#include <X11/Xlib.h>
#include <string>

class X11Display
{
    public:
        ~X11Display();
        X11Window* getDefaultRootWindow();
        Display* getDisplayId();
        static X11Display* makeDisplay(const std::string displayStr);
        static X11Display* makeDisplay();
    private:
        X11Display(const char* str);
        Display* display;
};


#endif //X11DISPLAY_H
