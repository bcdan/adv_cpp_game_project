//
// Created by dan on 29/06/2020.
//

#ifndef HW3_STRUCTURE_H
#define HW3_STRUCTURE_H


#include "Sim_object.h"

class Structure : public Sim_object {
private:
    Point _location;


public:
    Structure(Point &location, const string &name) :  Sim_object(name) {
        _location=location;
    }

    virtual string getType() const { return "Structure"; }

    virtual  Point get_location()  { return _location; }

    virtual void update() {} //for virtual purpose

    virtual int getAmount() const { return -1; }

    virtual void deposit(int ) {} //for virtual purpose

    virtual void withdraw(int ) {} //for virtual purpose
};


#endif //HW3_STRUCTURE_H
