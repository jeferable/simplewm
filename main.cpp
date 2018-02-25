#include "windowmanager.h"




int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = 1;
    WindowManager wm;
    return wm.run();
}
