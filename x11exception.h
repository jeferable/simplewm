#ifndef X11EXCEPTION_H
#define X11EXCEPTION_H

#include <exception>
#include <string>

class X11Exception: public std::exception
{
    public:
        explicit X11Exception(const char* message):message(message){}
        explicit X11Exception(std::string& message):message(message){}
        virtual ~X11Exception() throw() {}
        virtual const char* what() const throw(){
            return message.c_str();
        }
    protected:
        std::string message;
};


#endif //X11EXCEPTION_H
