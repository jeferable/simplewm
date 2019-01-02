#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "x11windowmanager.h"

#include "x11toplevelwindow.h"

class WindowManager: public X11WindowManager {
    public:
        WindowManager();
        ~WindowManager();
    private:
        //X11TopLevelWindow* 
        void onInitialized();
};

#endif //WINDOWMANAGER_H
