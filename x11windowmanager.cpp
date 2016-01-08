#include "x11windowmanager.h"

#include <iostream>

X11WindowManager::X11WindowManager() {

}

X11WindowManager::~X11WindowManager() {

}

int X11WindowManager::run() {
    try {
        display = new X11Display;
        rootWindow = display->getDefaultRootWindow();
        return 0;
    }
    catch (int a)
    {
        ///LOG(INFO)
        std::cout << "Error " << a << std::endl;
        return a;
    }
}

void X11WindowManager::checkWM()
{
    XSetErrorHandler(&X11WindowManager::onWMDetected);
    XSelectInput(display->getDisplayId(),
                 rootWindow->getId(),
                 SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(display->getDisplayId(), false);
}

int X11WindowManager::onWMDetected(Display* display, XErrorEvent* event)
{
    throw 1999; //Throwing an error
    return 0;
}
