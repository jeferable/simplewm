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
                onCreateNotify(X11EventFactory::event(e.xcreatewindow));
                break;
            case DestroyNotify:
                onDestroyNotify(X11EventFactory::event(e.xdestroywindow));
                break;
            case ReparentNotify:
                onReparentNotify(X11EventFactory::event(e.xreparent));
                break;
            case MapNotify:
                onMapNotify(X11EventFactory::event(e.xmap));
                break;
            case UnmapNotify:
                onUnmapNotify(X11EventFactory::event(e.xunmap));
                break;
            case ConfigureNotify:
                onConfigureNotify(X11EventFactory::event(e.xconfigure));
                break;
            case MapRequest:
                onMapRequest(X11EventFactory::event(e.xmaprequest));
                break;
            case ConfigureRequest:
                onConfigureRequest(X11EventFactory::event(e.xconfigurerequest));
                break;
            case ButtonPress:
                onButtonPress(X11EventFactory::event(e.xbutton));
                break;
            case ButtonRelease:
                onButtonRelease(X11EventFactory::event(e.xbutton));
                break;
            case MotionNotify:
                // Skip any already pending motion events.
                while (XCheckTypedWindowEvent(
                display->getDisplayId(), e.xmotion.window, MotionNotify, &e)) {}
                onMotionNotify(X11EventFactory::event(e.xmotion));
                break;
            case KeyPress:
                onKeyPress(X11EventFactory::event(e.xkey));
                break;
            case KeyRelease:
                onKeyRelease(X11EventFactory::event(e.xkey));
                break;
            default:
                LOG(WARNING) << "Ignored event";
        }
    }
}

void X11Application::onCreateNotify(X11CreateEvent e) {
}

void X11Application::onDestroyNotify(X11DestroyEvent e){
}

void X11Application::onReparentNotify(X11ReparentEvent e){
}

void X11Application::onMapNotify(X11MapEvent e){
}

void X11Application::onUnmapNotify(X11UnmapEvent e){
}

void X11Application::onConfigureNotify(X11ConfigureEvent e){
}

void X11Application::onMapRequest(X11MapRequestEvent e){
}

void X11Application::onConfigureRequest(X11ConfigureRequestEvent e){
}

void X11Application::onButtonPress(X11ButtonEvent e){
}

void X11Application::onButtonRelease(X11ButtonEvent e){
}

void X11Application::onMotionNotify(X11MotionEvent e){
}

void X11Application::onKeyPress(X11KeyEvent e){
}

void X11Application::onKeyRelease(X11KeyEvent e){
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
