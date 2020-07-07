//
// Created by dan on 29/06/2020.
//

#ifndef HW3_SIM_OBJECT_H
#define HW3_SIM_OBJECT_H


#include <utility>
#include <iostream>
#include "Geometry.h"
#include "Exceptions.h"

using namespace std;

class Sim_object {
private:
    string _name;
public:
    Sim_object(const string&name){
        _name=name;
    }

    virtual void update() {}
   virtual Point get_location() { return {0,0}; }

    const string &getName() const;
};


#endif //HW3_SIM_OBJECT_H
