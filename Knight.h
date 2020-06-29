//
// Created by dan on 29/06/2020.
//

#ifndef HW3_KNIGHT_H
#define HW3_KNIGHT_H


#include "Agent.h"

class Knight : public Agent{
public:
//    virtual void update() override;
    Knight(const string& name, int health, int state, Point &location, int speed) : Agent(name,health,state,location,speed){}

};


#endif //HW3_KNIGHT_H
