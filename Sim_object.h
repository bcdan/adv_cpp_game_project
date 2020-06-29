//
// Created by dan on 29/06/2020.
//

#ifndef HW3_SIM_OBJECT_H
#define HW3_SIM_OBJECT_H


#include "Geometry.h"

class Sim_object {
private:
    string _name;
public:
    Sim_object();
    ~Sim_object();

    virtual void update();
    virtual void broadcast_current_state();

    const string &getName() const;
};


#endif //HW3_SIM_OBJECT_H
