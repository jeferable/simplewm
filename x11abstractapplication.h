#ifndef X11ABSTRACTAPPLICATION_H
#define X11ABSTRACTAPPLICATION_H

class X11AbstractApplication {
    public:
        X11AbstractApplication(int argc, char* argv[]);
        X11AbstractApplication();
        virtual ~X11AbstractApplication();
        virtual int run() = 0;
};

#endif //X11APPLICATION
