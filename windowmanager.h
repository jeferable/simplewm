#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "x11windowmanager.h"

class WindowManager: public X11WindowManager {
    public:
        WindowManager();
        ~WindowManager();
        //void run();
};




#endif //WINDOWMANAGER_H
