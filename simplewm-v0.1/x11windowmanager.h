#ifndef X11WINDOWMANAGER_H
#define X11WINDOWMANAGER_H

#include "x11application.h"
#include "x11window.h"
#include "x11display.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <map>
class X11WindowManager: public X11Application {
    public:
        X11WindowManager();
        virtual ~X11WindowManager();
    private:
        Atom WM_PROTOCOLS;
        Atom WM_DELETE_WINDOW;
        X11Display* display;
        X11Window* rootWindow;
        std::map <Window, X11Window*> windowsMap;
        void checkWM();
        void frameWindow(Window w, bool createdBeforeWM);
        void init();
        void fetchWindows();
        static int onWMDetected(Display* display, XErrorEvent* event);
};

#endif
