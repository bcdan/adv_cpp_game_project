//
// Created by dan on 29/06/2020.
//

#ifndef HW3_SIM_OBJECT_H
#define HW3_SIM_OBJECT_H


#include <utility>
#include <iostream>
#include "Geometry.h"

using namespace std;

class Sim_object {
private:
    string _name;
public:
    Sim_object(const string&name){
        _name=name;
    }


//    ~Sim_object();
//
    virtual void update() {}
//    virtual void broadcast_current_state();
   virtual Point& get_location() {}

    const string &getName() const;
};


#endif //HW3_SIM_OBJECT_H
