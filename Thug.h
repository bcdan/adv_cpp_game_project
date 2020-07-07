//
// Created by dan on 29/06/2020.
//

#ifndef HW3_THUG_H
#define HW3_THUG_H


#include "Agent.h"
#include "Peasant.h"

#define MAX_HP 20
#define MAX_SPEED 30

class Thug : public Agent {
private:
    string _type; // type = thug
    string _target; // attack target name
public:
    Thug(const string &name, Point &startingLocation, int state = stopped, int health = 5, int speed = 0) :  Agent(name, health, state, startingLocation, speed) {
        _type="Thug";
    }

    virtual void course(double angle, int speed); //set moving course at specified speed
    virtual void position(Point dest, int speed); //set destination as point (x,y) at specified speed
    virtual void update() override;
    virtual bool attack(const shared_ptr<Agent>& peasant);
    bool inRange(Point p); // check if target is in range (if peasant's in range)
    void setToAttackPos(Point p); // position thug in peasant's radius

    const string &getTarget() const {
        return _target;
    }

    void setTarget(const string &target) {
        _target = target;
    }

    virtual string getType() const {return _type;}

};


#endif //HW3_THUG_H
