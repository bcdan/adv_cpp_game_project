//
// Created by dan on 29/06/2020.
//

#ifndef HW3_PEASANT_H
#define HW3_PEASANT_H


#include "Agent.h"

class Peasant : public Agent{
public:
      Peasant(const string& name, int health, int state, Point &location, int speed) : Agent(name,health,state,location,speed){}
//    virtual void update() override;
};


#endif //HW3_PEASANT_H
