#include "windowmanager.h"




int main(int argc, char* argv[])
{
    FLAGS_logtostderr = 1;
    WindowManager wm;
    return wm.run();
}
