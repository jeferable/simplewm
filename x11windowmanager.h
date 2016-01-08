#ifndef X11WINDOWMANAGER_H
#define X11WINDOWMANAGER_H

#include "x11abstractapplication.h"
#include "x11display.h"
#include "x11window.h"

#include <X11/Xlib.h>

class X11WindowManager: public X11AbstractApplication{
    public:
        X11WindowManager();
        virtual ~X11WindowManager();
        int run();
     private:
        X11Display* display;
	X11Window* rootWindow;
        void checkWM();
        static int onWMDetected(Display* display, XErrorEvent* event);
};

#endif //X11WINDOWMANAGER_H
