//
// Created by samuel on 06/06/2020.
//

#ifndef HW2_EXCEPTIONS_H
#define HW2_EXCEPTIONS_H

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
        explicit InputException(const char *what) : runtime_error(what) {}
    };

    class ArgsException : public runtime_error { //invalid file data exception
    public:
        explicit ArgsException(const char *what) : runtime_error(what) {}
    };
};


#endif //HW2_EXCEPTIONS_H
