#ifndef X11EVENT_H
#define X11EVENT_H

#include "x11object.h"

class X11DestroyEvent: X11Event;
class X11ReparentEvent: X11Event;
class X11MapEvent: X11Event;
class X11UnmapEvent: X11Event;
class X11ConfigureEvent: X11Event;
class X11MapRequestEvent: X11Event;
class X11ConfigureRequestEvent: X11Event;
class X11ButtonEvent: X11Event;
class X11MotionEvent: X11Event;
class X11KeyEvent: X11Event;

class X11Event: X11Object {
    public:
        X11Event() {

        }
        ~X11Event() {

        }
        static X11CreateEvent event(const XCreateWindowEvent& e){
            return X11CreateEvent();
        }

        static X11DestroyEvent event(const XDestroyWindowEvent& e){
            return X11DestroyEvent();
        }
        
        static X11ReparentEvent event(const XReparentEvent& e){
            return X11ReparentEvent();
        }
        
        static X11MapEvent event(const XMapEvent& e){
            return X11MapEvent();
        }
        
        static X11UnmapEvent event(const XUnmapEvent& e){
            return X11UnmapEvent();
        }
        
        static X11ConfigureEvent event(const XConfigureEvent& e){
            return X11ConfigureEvent();
        }
        
        static X11MapRequestEvent event(const XMapRequestEvent& e){
            return X11MapRequestEvent();
        }
        
        static X11ConfigureRequestEvent event(const XConfigureRequestEvent& e){
            return X11ConfigureRequestEvent();
        }
        
        static X11ButtonEvent event(const XButtonEvent& e){
            return X11ButtonEvent();
        }
        
        static X11MotionEvent event(const XMotionEvent& e){
            return X11MotionEvent();
        }
        
        static X11KeyEvent event(const XKeyEvent& e){
            return X11KeyEvent();
        }        
};

class X11CreateEvent: X11Event {
    public:
        X11CreateEvent(){}
        ~X11CreateEvent(){}

};

class X11DestroyEvent: X11Event {
    public:
        X11DestroyEvent(){}
        ~X11DestroyEvent(){}
};

class X11ReparentEvent: X11Event {
    public:
        X11ReparentEvent(){}
        ~X11ReparentEvent(){}
};

class X11MapEvent: X11Event {
    public:
        X11MapEvent(){}
        ~X11MapEvent(){}
};

class X11UnmapEvent: X11Event {
    public:
        X11UnmapEvent(){}
        ~X11UnmapEvent(){}
};

class X11ConfigureEvent: X11Event {
    public:
        X11ConfigureEvent(){}
        ~X11ConfigureEvent(){}
};

class X11MapRequestEvent: X11Event {
    public:
        X11MapRequestEvent(){}
        ~X11MapRequestEvent(){}
};

class X11ConfigureRequestEvent: X11Event {
    public:
        X11ConfigureRequestEvent(){}
        ~X11ConfigureRequestEvent(){}
};

class X11ButtonEvent: X11Event {
    public:
        X11ButtonEvent(){}
        ~X11ButtonEvent(){}
};

class X11MotionEvent: X11Event {
    public:
        X11MotionEvent(){}
        ~X11MotionEvent(){}
};

class X11KeyEvent {
    public:
        X11KeyEvent(){}
        ~X11KeyEvent(){}
};


#endif //X11EVENT_h