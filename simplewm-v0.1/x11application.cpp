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
    }
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
