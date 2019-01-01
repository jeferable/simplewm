#include "x11application.h"

#include <glog/logging.h>
#include <exception>
#include <iostream>

X11Application::X11Application(): running(false) {
}

X11Application::~X11Application() {
    LOG(INFO) << "Destroying X11Application";
    running = false;
    if (display != NULL) std::cout << display << "\n"; //Here Segmentation fault while deleting display
}

X11Display* X11Application::getDisplay(){
    return display;
}

void X11Application::run(){
    try {
    running = true;
    openDisplay();
    init();
    onInitialized();
    eventLoop();
    onCloseApplication();
    }
    catch (std::exception& e) {
        LOG(ERROR) << e.what();
    }
}

void X11Application::eventLoop() {
    while(running) {
        XEvent e;
        XNextEvent(display->getDisplayId(), &e);
        switch (e.type) {
            case CreateNotify:
                onCreateNotify(X11Event::event(e.xcreatewindow));
                break;
            case DestroyNotify:
                onDestroyNotify(X11Event::event(e.xdestroywindow));
                break;
            case ReparentNotify:
                onReparentNotify(X11Event::event(e.xreparent));
                break;
            case MapNotify:
                onMapNotify(X11Event::event(e.xmap));
                break;
            case UnmapNotify:
                onUnmapNotify(X11Event::event(e.xunmap));
                break;
            case ConfigureNotify:
                onConfigureNotify(X11Event::event(e.xconfigure));
                break;
            case MapRequest:
                onMapRequest(X11Event::event(e.xmaprequest));
                break;
            case ConfigureRequest:
                onConfigureRequest(X11Event::event(e.xconfigurerequest));
                break;
            case ButtonPress:
                onButtonPress(X11Event::event(e.xbutton));
                break;
            case ButtonRelease:
                onButtonRelease(X11Event::event(e.xbutton));
                break;
            case MotionNotify:
                // Skip any already pending motion events.
                while (XCheckTypedWindowEvent(
                display_, e.xmotion.window, MotionNotify, &e)) {}
                onMotionNotify(X11Event::event(e.xmotion));
                break;
            case KeyPress:
                onKeyPress(X11Event::event(e.xkey));
                break;
            case KeyRelease:
                onKeyRelease(X11Event::event(e.xkey));
                break;
            default:
                LOG(WARNING) << "Ignored event";
        }
    }
}

void onCreateNotify(X11CreateEvent e) {
}

void onDestroyNotify(X11DestroyEvent e){
}

void onReparentNotify(X11ReparentEvent e){
}

void onMapNotify(X11MapEvent e){
}

void onUnmapNotify(X11UnmapEvent e){
}

void onConfigureNotify(X11ConfigureEvent e){
}

void onMapRequest(X11MapRequestEvent e){
}

void onConfigureRequest(X11ConfigureRequestEvent e){
}

void onButtonPress(X11ButtonPressEvent e){
}

void onMotionNotify(X11MotionEvent e){
}

void onKeyPress(X11KeyPressEvent e){
}

void onKeyRelease(X11KeyReleaseEvent e){
}

void X11Application::init(){
}

void X11Application::onCloseApplication() {
}

void X11Application::onInitialized(){
}

void X11Application::openDisplay() {
    display = X11Display::makeDisplay();
}
