#ifndef X11WINDOW_H
#define X11WINDOW_H

#include <X11/Xlib.h>

class X11Window {
    public:
        X11Window(Window id = 0);
        virtual ~X11Window();
        Window getId();
    private:
        Window id;
};

#endif //X11WINDOW_H
