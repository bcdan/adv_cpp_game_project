//
// Created by dan on 29/06/2020.
//

#ifndef HW3_AGENT_H
#define HW3_AGENT_H


#include "Moving_object.h"
#include "Sim_object.h"

enum states {stopped, dead, Moving_to};

class Agent : public Moving_object, public Sim_object{
private:
    int _health;
    int _state;
public:
    void move_to(Point& p);
    Point& get_location() const;
    virtual void update();
};


#endif //HW3_AGENT_H
