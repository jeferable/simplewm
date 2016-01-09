#ifndef X11OBJECT_H
#define X11OBJECT_H

#include "x11display.h"

class X11Object {
    public:
        X11Object();
        X11Object(X11Display* display= 0, X11Object* parent = 0);
        virtual ~X11Object();
    protected:
        X11Display* getDisplay();
        void setDisplay(X11Display* d);
        X11Object* getParent();
        void setParent(Object* p);
    private:
        X11Display* display;
        X11Object* parent;
};


#endif //X11OBJECT_H