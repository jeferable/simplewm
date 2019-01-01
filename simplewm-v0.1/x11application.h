#ifndef X11APPLICATION_H
#define X11APPLICATION_H

#include "x11object.h"
#include "x11display.h"

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
        void openDisplay();
};


#endif //X11APPLICATION_H
