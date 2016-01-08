#ifndef X11DISPLAY_H
#define X11DISPLAY_H

#include "x11window.h"

#include <X11/Xlib.h>

class X11Display
{
    public:
        X11Display();
        ~X11Display();
        X11Window* getDefaultRootWindow();
        Display* getDisplayId();
    private:
        Display* display;
};


#endif //X11DISPLAY_H
