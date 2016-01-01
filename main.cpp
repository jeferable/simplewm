#include "windowmanager.h"

#include <glog/logging.h>


int main(int argc, char* argv[])
{
    WindowManager wm;
    LOG(INFO) << "Starting a window manager...";
    wm.run();
    return 0;
}
