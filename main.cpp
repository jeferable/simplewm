#include "windowmanager.h"

#include <glog/logging.h>


int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = 1;
    WindowManager wm;
    LOG(INFO) << "Starting a window manager...";
    wm.run();
    return 0;
}
