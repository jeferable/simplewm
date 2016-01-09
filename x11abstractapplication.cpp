#include "x11abstractapplication.h"

#include <exception>

X11AbstractApplication::X11AbstractApplication()
    :errorCode(0), running(false) {
}

X11AbstractApplication::X11AbstractApplication(int argc, char* argv[])
    :errorCode(0), running(false) {
    
}

X11AbstractApplication::~X11AbstractApplication() {
}

void X11AbstractApplication::eventLoop() {
    running = true;
    while(running) {
        XEvent e;
        XNextEvent(display->getDisplayId(), &e);
        switch(e.type) {
            case CreateNotify: 
                onCreateNotify(e.xcreatewindow);
                break;
            case DestroyNotify: 
                onDestroyNotyfy(e.xdestroywindow);
                break;
            case ReparentNotify: 
                onReparentNotify(e.xreperent);
                break;
            case MapNotify: 
                onMapNotify(e.xmap);
                break;
            case UnmapNotify: 
                onUnmapNotify(e.xunmap);
                break;
            case ConfigureNotify: 
                onConfigureNotify(e.xconfigure);
                break;
            case MapRequest:
                onMapRequest(e.xmaprequest);
                break;
            case ConfigureRequest:
                onConfigureRequest(e.xconfigurerequest)
            case ButtonPress: 
                onButtonPress(e.xbutton);
                break;
            case ButtonRelease: 
                onButtonRelease(e.xbutton);
                break;
            case MotionNotify:  
                onMotionNotify(e.xmotion);
                break;
            case KeyPress:
                onKeyPress(e.xkey);
                break;
            case KeyRelease: 
                onKeyPress(e.xkey);
                break;
            default: ;
        }
}

void X11AbstractApplication::init() {
    
}

int X11AbstractApplication::run() {
    try {
        openDisplay();
        init();
        eventLoop();
    }
    catch (std::exception &ex)
    {
        LOG(ERROR) << ex.what();
        errorCode = 1;
    }
    return errorCode;
}

void X11AbstractApplication::openDisplay() {
    X11Display* d = new X11Display;
    setDisplay(d);
}

void X11AbstractApplication::onCreateNotify(const XCreateWindowEvents& e) {
    
}

void X11AbstractApplication::onDestroyNotyfy(const XDestroyWindowEvent& e) {
    
}

void X11AbstractApplication::onReparentNotify(const XReparentEvent& e) {
    
}

void X11AbstractApplication::onMapNotify(const XMapEvent& e) {
    
}

void X11AbstractApplication::onUnmapNotify(const XUnmapEvent& e) {
    
}

void X11AbstractApplication::onConfigureNotify(const XConfigureEvent& e) {
    
}

void X11AbstractApplication::onMapRequest(const XMapRequestEvent& e) {
    
}

void X11AbstractApplication::onConfigureRequest(const XConfigureRequestEvent& e) {
    
}

void X11AbstractApplication::onButtonPress(const XButtonEvent& e) {
    
}

void X11AbstractApplication::onButtonRelease(const XButtonEvent& e) {
    
}

void X11AbstractApplication::onMotionNotify(const XMotionEvent& e) {
    
}

void X11AbstractApplication::onKeyPress(const XKeyEvent& e) {
    if (e.state & Mod1Mask) {
        if (e.keycode == XKeysymToKeycode(display->getDisplayId(), XK_F4))
            LOG(INFO) << "The command Alt + F4 has been pressed";
        if (e.keycode == XKeysymToKeycode(display->getDisplayId(), XK_Tab))
            LOG(INFO) << "The command Alt + TAB has been pressed";
    }
}

void X11AbstractApplication::onKeyRelease(const XKeyEvent& e) {
    
}

int X11WindowManager::onXError(Display* display, XErrorEvent* event)
{
    const int MAX_ERROR_TEXT_LENGTH = 1024;
    char error_text[MAX_ERROR_TEXT_LENGTH];
    XGetErrorText(display, e->error_code, error_text, sizeof(error_text));
    LOG(ERROR) << "Received X error:\n"
               << "    Request: " << int(e->request_code)
               << " - " << XRequestCodeToString(e->request_code) << "\n"
               << "    Error code: " << int(e->error_code)
               << " - " << error_text << "\n"
               << "    Resource ID: " << e->resourceid;
    return 0;
}