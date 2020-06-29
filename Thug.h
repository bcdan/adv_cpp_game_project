//
// Created by dan on 29/06/2020.
//

#ifndef HW3_THUG_H
#define HW3_THUG_H


#include "Agent.h"

class Thug : public Agent{
public:
    Thug(const string& name, int health, int state, Point &location, int speed) : Agent(name,health,state,location,speed){}

//    virtual void update() override;
//    void attack();
};


#endif //HW3_THUG_H
