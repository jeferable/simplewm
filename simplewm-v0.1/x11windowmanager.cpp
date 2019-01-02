#include "x11windowmanager.h"

#include <glog/logging.h>


void X11WindowManager::frameWindow(Window w, bool createdBeforeWM) {
    const unsigned int BORDER_WIDTH = 3;
    const unsigned long BORDER_COLOR = 0xff0000;
    const unsigned long BG_COLOR = 0xeeeeee;

    XWindowAttributes x_window_attrs;
    XGetWindowAttributes(display->getDisplayId(), w, &x_window_attrs);
    if (createdBeforeWM) {
        if (x_window_attrs.override_redirect ||
            x_window_attrs.map_state != IsViewable) {
            return;
        }
    }
    const Window frame = XCreateSimpleWindow(
        display->getDisplayId(),
        rootWindow->getId(),
        x_window_attrs.x,
        x_window_attrs.y,
        x_window_attrs.width,
        x_window_attrs.height,
        BORDER_WIDTH,
        BORDER_COLOR,
        BG_COLOR);
    const Window frameTitle = XCreateSimpleWindow(
        display->getDisplayId(),
        frame,
        0, 0,
        x_window_attrs.width, 50,
        0, 0, BORDER_COLOR);
    );
    XSelectInput(display->getDisplayId(), frame, 
                 SubstructureRedirectMask | SubstructureNotifyMask);
    XAddToSaveSet(display->getDisplayId(), w);
    XReparentWindow(display->getDisplayId(), w, frame, 0, 50);
    XMapWindow(display->getDisplayId(), frame);
    
}


X11WindowManager::X11WindowManager(){
}

X11WindowManager::~X11WindowManager(){
    if (display != nullptr) delete display;
    if (rootWindow != nullptr) delete rootWindow;
}


void X11WindowManager::init() {
    LOG(INFO) << "Initializing X11WindowMananger";
    display = getDisplay();
    rootWindow = display->getDefaultRootWindow();
    WM_PROTOCOLS = XInternAtom(display->getDisplayId(), "WM_PROTOCOLS", false);
    WM_DELETE_WINDOW = XInternAtom(display->getDisplayId(), "WM_DELETE_WINDOW", false);
    checkWM();
    fetchWindows();
}

void X11WindowManager::checkWM() {
    LOG(INFO) << "Checking another window mananger";
    XSetErrorHandler(&X11WindowManager::onWMDetected);
    XSelectInput(display->getDisplayId(), rootWindow->getId(),
                 SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(display->getDisplayId(), false);
}

void X11WindowManager::fetchWindows() {
    LOG(INFO) << "Fetching windows";
    XGrabServer(display->getDisplayId());
    Window returnedRoot, returnedParent;
    Window* topLevelWindows;
    unsigned int numTopLevelWindows;
    XQueryTree(display->getDisplayId(),
               rootWindow->getId(),
               &returnedRoot, &returnedParent,
               &topLevelWindows,
               &numTopLevelWindows);
     for(unsigned int i(0); i < numTopLevelWindows; ++i) {
         Window w = topLevelWindows[i];
         windowsMap[w] = new X11Window(w);
         frameWindow(w, true);
     }
     LOG(INFO) << "Found: " << numTopLevelWindows << ": window(s)";
     for (auto const& x:windowsMap) {
         LOG(INFO) << x.first;
     }
     XFree(topLevelWindows);
     XUngrabServer(display->getDisplayId());
}

int X11WindowManager::onWMDetected(Display* display, XErrorEvent* event) {
    LOG(ERROR) << "Another window manager has found.";
    //running = false;
    return 0;
}
