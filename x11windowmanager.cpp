#include "x11windowmanager.h"

#include <exception>
#include <iostream>

X11WindowManager::X11WindowManager() {

}

X11WindowManager::~X11WindowManager() {
    //windowsMap.free();
    for (std::map<Window, X11Window*>::iterator it = windowsMap.begin();
         it!=windowsMap.end(); ++it)
        if (!it->second) delete it->second;
    windowsMap.clear();
}

int X11WindowManager::init() {
        rootWindow = display->getDefaultRootWindow();
        WM_PROTOCOLS = XInternAtom(display->getDisplayId(),
                       "WM_PROTOCOLS", false);
        WM_DELETE_WINDOW = XInternAtom(display->getDisplayId(),
                       "WM_DELETE_WINDOW", false);
        checkWM();
        XSetErrorHandler(&X11WindowManager::onXError);
        fetchWindows();
}

void X11WindowManager::checkWM()
{
    XSetErrorHandler(&X11WindowManager::onWMDetected);
    XSelectInput(display->getDisplayId(),
                 rootWindow->getId(),
                 SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(display->getDisplayId(), false);
}

void X11WindowManager::fetchWindows() {
    XGrabServer(display->getDisplayId());
    Window returnedRoot, returnedParent;
    Window* topLevelWindows;
    unsigned int numTopLevelWindows;
    XQueryTree(display->getDisplayId(),
               rootWindow->getId(),
               &returnedRoot, &returnedParent,
               &topLevelWindows,
               &numTopLevelWindows);
    for (unsigned int i = 0; i < numTopLevelWindows; ++i) {
          Window w = topLevelWindows[i];
          windowsMap[w] = new X11Window(w);
          XGrabKey(display->getDisplayId(),
                   XKeysymToKeycode(display->getDisplayId(), XK_F4),
                   Mod1Mask,
                   w, false,
                   GrabModeAsync, GrabModeAsync);
          XGrabKey(display->getDisplayId(),
                   XKeysymToKeycode(display->getDisplayId(), XK_Tab),
                   Mod1Mask,
                   w, false,
                   GrabModeAsync, GrabModeAsync);
    }
    for (std::map<Window, X11Window*>::iterator it = windowsMap.begin();
         it!=windowsMap.end();
         ++it)
        std::cout << it->first << std::endl;
    XFree(topLevelWindows);
    XUngrabServer(display->getDisplayId());
}

int X11WindowManager::onWMDetected(Display* display, XErrorEvent* event)
{
    throw 1999; //Throwing an error
    return 0;
}