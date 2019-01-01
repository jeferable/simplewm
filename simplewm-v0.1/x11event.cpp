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
X11EventFactory::X11CreateEvent event(const XCreateWindowEvent& e){
    return X11CreateEvent();
}

X11EventFactory::X11DestroyEvent event(const XDestroyWindowEvent& e){
    return X11DestroyEvent();
}

X11EventFactory::X11ReparentEvent event(const XReparentEvent& e){
    return X11ReparentEvent();
}

X11EventFactory::X11MapEvent event(const XMapEvent& e){
    return X11MapEvent();
}

X11EventFactory::X11UnmapEvent event(const XUnmapEvent& e){
    return X11UnmapEvent();
}

X11EventFactory::X11ConfigureEvent event(const XConfigureEvent& e){
    return X11ConfigureEvent();
}

X11EventFactory::X11MapRequestEvent event(const XMapRequestEvent& e){
    return X11MapRequestEvent();
}

X11EventFactory::X11ConfigureRequestEvent event(const XConfigureRequestEvent& e){
    return X11ConfigureRequestEvent();
}

X11EventFactory::X11ButtonEvent event(const XButtonEvent& e){
    return X11ButtonEvent();
}

X11EventFactory::X11MotionEvent event(const XMotionEvent& e){
    return X11MotionEvent();
}
        
X11EventFactory::X11KeyEvent event(const XKeyEvent& e){
    return X11KeyEvent();
}        

