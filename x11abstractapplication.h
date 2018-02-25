#ifndef X11ABSTRACTAPPLICATION_H
#define X11ABSTRACTAPPLICATION_H

#include "x11object.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

class X11AbstractApplication: protected X11Object  {
    public:
        X11AbstractApplication(int argc, char* argv[]);
        X11AbstractApplication();
        virtual ~X11AbstractApplication();
        void eventLoop();
        virtual void init() = 0;
        int run();
    private:
        bool running;
        int errorCode;
        void openDisplay();
        void onCreateNotify(const XCreateWindowEvents& e);
        void onDestroyNotyfy(const XDestroyWindowEvent& e);
        void onReparentNotify(const XReparentEvent& e);
        void onMapNotify(const XMapEvent& e);
        void onUnmapNotify(const XUnmapEvent& e);
        void onConfigureNotify(const XConfigureEvent& e);
        void onMapRequest(const XMapRequestEvent& e);
        void onConfigureRequest(const XConfigureRequestEvent& e);
        void onButtonPress(const XButtonEvent& e);
        void onButtonRelease(const XButtonEvent& e);
        void onMotionNotify(const XMotionEvent& e);
        void onKeyPress(const XKeyEvent& e);
        void onKeyRelease(const XKeyEvent& e);
        static int onXError(Display* display, XErrorEvent* event);
};

#endif //X11APPLICATION
