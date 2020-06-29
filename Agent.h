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
    Agent(const string& name, int health, int state, Point &location, int speed): _health(health), _state(state),Moving_object(location,speed),Sim_object(name){}
//    void move_to(Point& p);
//    virtual void update();
};


#endif //HW3_AGENT_H