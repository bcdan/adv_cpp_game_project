//
// Created by dan on 29/06/2020.
//

#ifndef HW3_AGENT_H
#define HW3_AGENT_H


#include "Moving_object.h"
#include "Sim_object.h"


enum states {stopped, dead, Moving_to_destination, Moving_on_course,working};

class Agent : public Moving_object, public Sim_object{
private:
    int _health;
    int _state;
    double _angle;
public:
    double getAngle() const;

    void setAngle(double angle);

public:
    Agent(const string& name, int health, int state, Point &location, int speed): _health(health), _state(state),_angle(0),Moving_object(location,speed),Sim_object(name){}
//    void move_to(Point& p);
    virtual void update() {}
    virtual int getInventory() const {}
    virtual string getType() const {return "Agent";}
    virtual void course(double angle); //set moving course at specified speed
    virtual void position(Point dest); //set destination as point (x,y) at specified speed



    int getHealth() const {
        return _health;
    }

    void setHealth(int health) {
        _health = health;
    }

    int getState() const {
        return _state;
    }

    void setState(int state) {
        _state = state;
    }
};


#endif //HW3_AGENT_H
