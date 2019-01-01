#include "windowmanager.h"

#include <glog/logging.h>

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::onInitialized(){
    LOG(INFO) << "Window manager has been launched.";
}
