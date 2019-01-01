#include "x11event.h"

X11CreateEvent::X11CreateEvent(){}
X11CreateEvent::~X11CreateEvent(){}
X11DestroyEvent::X11DestroyEvent(){}
X11DestroyEvent::~X11DestroyEvent(){}
X11ReparentEvent::X11ReparentEvent(){}
X11ReparentEvent::~X11ReparentEvent(){}
X11MapEvent::X11MapEvent(){}
X11MapEvent::~X11MapEvent(){}
X11UnmapEvent::X11UnmapEvent(){}
X11UnmapEvent::~X11UnmapEvent(){}
X11ConfigureEvent::X11ConfigureEvent(){}
X11ConfigureEvent::~X11ConfigureEvent(){}
X11MapRequestEvent::X11MapRequestEvent(){}
X11MapRequestEvent::~X11MapRequestEvent(){}
X11ConfigureRequestEvent::X11ConfigureRequestEvent(){}
X11ConfigureRequestEvent::~X11ConfigureRequestEvent(){}
X11ButtonEvent::X11ButtonEvent(){}
X11ButtonEvent::~X11ButtonEvent(){}
X11MotionEvent::X11MotionEvent(){}
X11MotionEvent::~X11MotionEvent(){}
X11KeyEvent::X11KeyEvent(){}
X11KeyEvent::~X11KeyEvent(){}

X11Event::X11Event() {

}
X11Event::~X11Event() {

}
X11Event::X11CreateEvent event(const XCreateWindowEvent& e){
    return X11CreateEvent();
}

X11Event::X11DestroyEvent event(const XDestroyWindowEvent& e){
    return X11DestroyEvent();
}

X11Event::X11ReparentEvent event(const XReparentEvent& e){
    return X11ReparentEvent();
}

X11Event::X11MapEvent event(const XMapEvent& e){
    return X11MapEvent();
}

X11Event::X11UnmapEvent event(const XUnmapEvent& e){
    return X11UnmapEvent();
}

X11Event::X11ConfigureEvent event(const XConfigureEvent& e){
    return X11ConfigureEvent();
}

X11Event::X11MapRequestEvent event(const XMapRequestEvent& e){
    return X11MapRequestEvent();
}

X11Event::X11ConfigureRequestEvent event(const XConfigureRequestEvent& e){
    return X11ConfigureRequestEvent();
}

X11Event::X11ButtonEvent event(const XButtonEvent& e){
    return X11ButtonEvent();
}

X11Event::X11MotionEvent event(const XMotionEvent& e){
    return X11MotionEvent();
}
        
X11Event::X11KeyEvent event(const XKeyEvent& e){
    return X11KeyEvent();
}        

