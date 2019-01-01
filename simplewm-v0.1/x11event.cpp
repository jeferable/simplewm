#include "x11event.h"

X11Event::X11Event() {
}
X11Event::~X11Event() {
}

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

X11EventFactory::X11EventFactory() {

}
X11EventFactory::~X11EventFactory() {

}
X11CreateEvent X11EventFactory::event(const XCreateWindowEvent& e){
    return X11CreateEvent();
}

X11DestroyEvent X11EventFactory::event(const XDestroyWindowEvent& e){
    return X11DestroyEvent();
}

X11ReparentEvent X11EventFactory::event(const XReparentEvent& e){
    return X11ReparentEvent();
}

X11MapEvent X11EventFactory::event(const XMapEvent& e){
    return X11MapEvent();
}

X11UnmapEvent X11EventFactory::event(const XUnmapEvent& e){
    return X11UnmapEvent();
}

X11ConfigureEvent X11EventFactory::event(const XConfigureEvent& e){
    return X11ConfigureEvent();
}

X11MapRequestEvent X11EventFactory::event(const XMapRequestEvent& e){
    return X11MapRequestEvent();
}

X11ConfigureRequestEvent X11EventFactory::event(const XConfigureRequestEvent& e){
    return X11ConfigureRequestEvent();
}

X11ButtonEvent X11EventFactory::event(const XButtonEvent& e){
    return X11ButtonEvent();
}

X11MotionEvent X11EventFactory::event(const XMotionEvent& e){
    return X11MotionEvent();
}
        
X11KeyEvent X11EventFactory::event(const XKeyEvent& e){
    return X11KeyEvent();
}        

