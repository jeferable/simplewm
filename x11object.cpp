#include "x11object.h"

X11Object::X11Object: display(0), parent(0) {
    
}

X11Object::X11Object(X11Display* display= 0, X11Object* parent = 0)
    :display(0), parent(0) {
    
}

X11Object::~X11Object() {
    
}

X11Display* X11Object::getDisplay() {
    return display;
}

void X11Object::setDisplay(X11Display* d) {
    display = d;
}

X11Object* X11Object::getParent() {
    return parent;
}

void X11Object::setParent(Object* p) {
    parent = p;
}