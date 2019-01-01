#include "windowmanager.h"

#include <glog/logging.h>

int main(int argc, char** argv)
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = 1;
    WindowManager wm;
    wm.run();
    return 0;
}
