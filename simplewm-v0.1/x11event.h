#ifndef X11EVENT_H
#define X11EVENT_H

#include "x11object.h"

class X11Event: X11Object {
    public:
        X11Event();
        ~X11Event();
};

class X11CreateEvent: X11Event {
    public:
        X11CreateEvent();
        ~X11CreateEvent();
};

class X11DestroyEvent: X11Event {
    public:
        X11DestroyEvent();
        ~X11DestroyEvent();
};

class X11ReparentEvent: X11Event {
    public:
        X11ReparentEvent();
        ~X11ReparentEvent();
};

class X11MapEvent: X11Event {
    public:
        X11MapEvent();
        ~X11MapEvent();
};

class X11UnmapEvent: X11Event {
    public:
        X11UnmapEvent();
        ~X11UnmapEvent();
};

class X11ConfigureEvent: X11Event {
    public:
        X11ConfigureEvent();
        ~X11ConfigureEvent();
};

class X11MapRequestEvent: X11Event {
    public:
        X11MapRequestEvent();
        ~X11MapRequestEvent();
};

class X11ConfigureRequestEvent: X11Event {
    public:
        X11ConfigureRequestEvent();
        ~X11ConfigureRequestEvent();
};

class X11ButtonEvent: X11Event {
    public:
        X11ButtonEvent();
        ~X11ButtonEvent();
};

class X11MotionEvent: X11Event {
    public:
        X11MotionEvent();
        ~X11MotionEvent();
};

class X11KeyEvent: X11Event {
    public:
        X11KeyEvent();
        ~X11KeyEvent();
};

class X11EventFactory: X11Object {
    public:
        X11EventFactory();
        ~X11EventFactory(); 
        static X11CreateEvent event(const XCreateWindowEvent& e);
        static X11DestroyEvent event(const XDestroyWindowEvent& e);
        static X11ReparentEvent event(const XReparentEvent& e);
        static X11MapEvent event(const XMapEvent& e);
        static X11UnmapEvent event(const XUnmapEvent& e);
        static X11ConfigureEvent event(const XConfigureEvent& e);
        static X11MapRequestEvent event(const XMapRequestEvent& e);
        static X11ConfigureRequestEvent event(const XConfigureRequestEvent& e);
        static X11ButtonEvent event(const XButtonEvent& e);
        static X11MotionEvent event(const XMotionEvent& e);
        static X11KeyEvent event(const XKeyEvent& e);
};

#endif //X11EVENT_h
