#ifndef X11APPLICATION_H
#define X11APPLICATION_H

#include "x11object.h"
#include "x11display.h"
#include "x11event.h"

class  X11Application: protected X11Object {
    public:
        X11Application();
        ~X11Application();
        X11Display* getDisplay();
        void run();
     private:
        bool running;
        X11Display* display;
        void eventLoop();
        virtual void init();
        virtual void onCloseApplication();
        virtual void onInitialized();

        virtual void onCreateNotify(X11CreateEvent e);
        virtual void onDestroyNotify(X11DestroyEvent e);
        virtual void onReparentNotify(X11ReparentEvent e);
        virtual void onMapNotify(X11MapEvent e);
        virtual void onUnmapNotify(X11UnmapEvent e);
        virtual void onConfigureNotify(X11ConfigureEvent e);
        virtual void onMapRequest(X11MapRequestEvent e);
        virtual void onConfigureRequest(X11ConfigureRequestEvent e);
        virtual void onButtonPress(X11ButtonEvent e);
        virtual void onButtonRelease(X11ButtonEvent e);
        virtual void onMotionNotify(X11MotionEvent e);
        virtual void onKeyPress(X11KeyEvent e);
        virtual void onKeyRelease(X11KeyEvent e);


        void openDisplay();
};


#endif //X11APPLICATION_H
