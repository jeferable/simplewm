#include "windowmanager.h"

#include <glog/logging.h>

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::run()
{
    LOG(INFO) << "The window manager is running...";
}
