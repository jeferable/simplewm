#ifndef X11WINDOWMANAGER_H
#define X11WINDOWMANAGER_H

#include "x11abstractapplication.h"
#include "x11display.h"
#include "x11window.h"

#include <map>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

class X11WindowManager: public X11AbstractApplication{
    public:
        X11WindowManager();
        virtual ~X11WindowManager();
        int run();
        void init();
    private:
        Atom WM_PROTOCOLS;
        Atom WM_DELETE_WINDOW;
        X11Display* display;
	    X11Window* rootWindow;
        std::map<Window, X11Window*> windowsMap;
        void checkWM();
        void fetchWindows();
        static int onWMDetected(Display* display, XErrorEvent* event);
};

#endif //X11WINDOWMANAGER_H
