
#ifndef HW3_EXCEPTIONS_H
#define HW3_EXCEPTIONS_H

#include <exception>
#include <iostream>

using namespace std;

class Exceptions : public runtime_error{
public:
    explicit Exceptions(const char *what) : runtime_error(what) {}

    class FileErrorException : public runtime_error { //File handling exception
    public:
        explicit FileErrorException(const char *what) : runtime_error(what) {}
    };

    class InputException : public runtime_error { //input handling exception
    public:
        explicit InputException(const string& what) : runtime_error(what) {}
    };

    class ArgsException : public runtime_error { //invalid file data exception
    public:
        explicit ArgsException(const char *what) : runtime_error(what) {}
    };

    class Agent_Not_Found_Exception : public runtime_error { //input handling exception
    public:
        explicit Agent_Not_Found_Exception(const string& what) : runtime_error(what) {}
    };

    class Wrong_Type_Exception : public runtime_error { //input handling exception
    public:
        explicit Wrong_Type_Exception(const string &what) : runtime_error(what) {}
    };


};


#endif //HW3_EXCEPTIONS_H
